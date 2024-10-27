import json


list1 = [{"name": "方", "age": 18}, {"name": "Chen", "age": 20}, {"name": "Wang", "age": 16}]
json_str = json.dumps(list1, ensure_ascii=False)
print(json_str)


dict1 = {"name": "方", "age": 18}
json_str2 = json.dumps(dict1, ensure_ascii=False)
print(json_str2)

l = json.loads(json_str)
print(type(l))

n = json.loads(json_str2)
print(type(n))
