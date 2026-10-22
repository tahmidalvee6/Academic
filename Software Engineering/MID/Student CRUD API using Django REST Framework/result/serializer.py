from rest_framework import serializers
from .models import Student

class StudentSerializer(serializers.Serializer):
    name = serializers.CharField(max_length = 255)
    roll = serializers.IntegerField()
    section = serializers.CharField(max_length= 20)

    def create(self, validated_data):
        return Student.objects.create(**validated_data)
    def update(self, instance, validated_data):
        instance.name = validated_data.get('name',instance.name)
        instance.roll = validated_data.get('roll',instance.roll)
        instance.section = validated_data.get('section',instance.section)
        instance.save()
        return instance
