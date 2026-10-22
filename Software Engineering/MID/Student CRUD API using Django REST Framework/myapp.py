import requests
import json

URL = "http://127.0.0.1:8000/creatstudent/"

PUT_ID = 2
PATCH_ID = 3
DELETE_ID = 8

data = {'name': 'Nasimul Islam', 'roll': 45, 'section': '6DM'}
r = requests.post(url=URL, data=json.dumps(data))
print('POST', r.json())

data = {'id': PUT_ID, 'name': 'Rahim', 'roll': 22, 'section': '7DM'}
r = requests.put(url=URL, data=json.dumps(data))
print('PUT', r.json())

data = {'id': PATCH_ID, 'name': 'Karim'}
r = requests.patch(url=URL, data=json.dumps(data))
print('PATCH', r.json())

data = {'id': DELETE_ID}
r = requests.delete(url=URL, data=json.dumps(data))
print('DELETE', r.json())