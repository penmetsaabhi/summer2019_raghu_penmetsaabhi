import os
import django
import openpyxl
os.environ.setdefault('DJANGO_SETTINGS_MODULE','homeproject.settings')
django.setup()
from todoapp.models import *
def addData():
    ToDoList(name="dailyroutine").save()
    ToDoItem(description="Wahingclothes",todolist=ToDoList.objects.get(name="dailyroutine")).save()
    ToDoItem(description="shopping", todolist=ToDoList.objects.get(name="dailyroutine")).save()
    ToDoItem(description="Wahingdishes", todolist=ToDoList.objects.get(name="dailyroutine")).save()
    ToDoItem(description="cleaningHouse", todolist=ToDoList.objects.get(name="dailyroutine")).save()
    ToDoItem(description="movie", todolist=ToDoList.objects.get(name="dailyroutine")).save()
if __name__ == '__main__':
    #addData()
    pass