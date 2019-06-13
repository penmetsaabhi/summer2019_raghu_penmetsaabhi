from django.contrib import admin
from todoapp.models import  *
# Register your models here.
admin.site.register(ToDoList)
admin.site.register(ToDoItem)