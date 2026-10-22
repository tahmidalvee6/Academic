from django.shortcuts import render
from .models import Student
from django.http import HttpResponse
from .serializer import StudentSerializer
from rest_framework.renderers import JSONRenderer
import io
from rest_framework.parsers import JSONParser
from django.views.decorators.csrf import csrf_exempt

# view one student 
def studentview(request,pk):
    stu = Student.objects.get(id = pk)
    serializer = StudentSerializer(stu)
    json_data = JSONRenderer().render(data=serializer.data)
    return HttpResponse(json_data)

# view all student list
def studentListview(request):
    stu = Student.objects.all()
    serializer = StudentSerializer(stu,many=True)
    json_data = JSONRenderer().render(data=serializer.data)
    return HttpResponse(json_data)

# create a new data
@csrf_exempt
def createStudentView(request):
    if request.method == 'POST':
        json_data = request.body
        stream_data = io.BytesIO(json_data)
        parser_data = JSONParser().parse(stream_data)
        serializer = StudentSerializer(data = parser_data)

        if serializer.is_valid():
            serializer.save()
            res = {'msg':'Data Save Successfully'}
            json_res = JSONRenderer().render(res)
            return HttpResponse(json_res,content_type='application/json')
        error = serializer.errors()
        return HttpResponse(error,content_type = 'application/json')

# update the data 
    if request.method == 'PUT':
        json_data = request.body
        stream_data = io.BytesIO(json_data)
        parse_data = JSONParser().parse(stream_data)
        id = parse_data.get('id')
        query = Student.objects.get(id = id)
        serializer = StudentSerializer(query,data = parse_data)
        if serializer.is_valid():
            serializer.save()
            res = {'msg':'data updated successfully!'}
            json_res = JSONRenderer().render(res)
            return HttpResponse(json_res,content_type = 'application/json')
        json_res = serializer.errors()
        return HttpResponse(json_res,content_type = 'application/json')
    
# update only single data
    if request.method == 'PATCH':
        json_data = request.body
        stream_data = io.BytesIO(json_data)
        parse_data = JSONParser().parse(stream_data)
        id = parse_data.get('id')
        query = Student.objects.get(id = id)
        serializer = StudentSerializer(query,data = parse_data,partial = True)
        if serializer.is_valid():
            serializer.save()
            res = {'msg':'data updated successfully!'}
            json_res = JSONRenderer().render(res)
            return HttpResponse(json_res,content_type = 'application/json')
        json_res = serializer.errors()
        return HttpResponse(json_res,content_type = 'application/json')

    if request.method == 'DELETE':
        json_data = request.body
        stream_data = io.BytesIO(json_data)
        parsed_data = JSONParser().parse(stream_data)
        id = parsed_data.get('id')
        query = Student.objects.get(id = id)
        query.delete()
        res = {'msg':'Data deleted Successfully!!!'}
        json_res = JSONRenderer().render(res)
        return HttpResponse(json_res,content_type = 'application/json')