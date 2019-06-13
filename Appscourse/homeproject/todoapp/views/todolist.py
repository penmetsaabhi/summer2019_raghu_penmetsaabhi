from django.urls import resolve
from django.views import View
from todoapp.models import *
from todoapp.forms import todoform
from django.shortcuts import render,redirect
class TodoView(View):
    def get(self,request,**kwargs):
        if(kwargs):
            todoitem=ToDoItem.objects.all().filter(todolist__id=kwargs['id'])
            return render(
                request,
                template_name="todoitem.html",
                context={
                    "values": todoitem,
                    "id":kwargs["id"]
                }
            )
        todolist = ToDoList.objects.all()
        return render(
            request,
            template_name="todo.html",
            context={
            "values": todolist,
            }
        )
class AddtodolistView(View):
    def get(self,request,*args,**kwargs):
        form=todoform.todoListForm()
        """if resolve(request.path_info).url_name=='delete':
            College.objects.get(id=kwargs['id']).delete()
            return redirect("colleges")
        if kwargs:
            coll=College.objects.get(**kwargs)
            form=college.CollegeForm(instance=coll)"""
        return render(
            request,
            template_name="todolistForm.html",
            context={
                "form":form
            }
         )
    def post(self,request,*args,**kwargs):
        form=todoform.todoListForm(request.POST)
        if(form.is_valid()):
            form.save()
            return redirect("todo")
