from django.urls import resolve
from django.views import View
from todoapp.models import *
from todoapp.forms import todoform
from django.shortcuts import render,redirect
class Addtodoitem(View):
    def get(self,request,*args,**kwargs):
        form=todoform.todoItemForm()
        return render(
            request,
            template_name="todoitemForm.html",
            context={
                "form": form
            }
        )
    def post(self,request,*args,**kwargs):
        form=todoform.todoItemForm(request.POST)
        if(form.is_valid()):
            item=form.save(commit=False)
            item.todolist=ToDoList.objects.all().filter(id=kwargs['id'])[0]
            item.save()
            return redirect("todoitem",kwargs['id'])

