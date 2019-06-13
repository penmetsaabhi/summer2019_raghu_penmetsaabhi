from django.urls import resolve
from django.views import View
from onlineapp.models import *
from django.shortcuts import render,redirect
from onlineapp.forms import college
from django.contrib.auth.mixins import LoginRequiredMixin
class AddStudentView(View):
    def get(self, request, *args, **kwargs):
        form1= college.StudentForm()
        form2=college.MocktestForm()
        if resolve(request.path_info).url_name=='deleteStudent':
            Student.objects.get(id=kwargs['id2']).delete()
            return redirect("students",kwargs['id'])
        if resolve(request.path_info).url_name=='editStudent':
            stu = Student.objects.get(id=kwargs['id2'])
            mock = MockTest1.objects.get(student=stu)
            form1 = college.StudentForm( instance=stu)
            form2 = college.MocktestForm( instance=mock)
        return render(
            request,
            template_name="AddStudentform.html",
            context={
                "form1": form1,
                "form2":form2
            }
        )

    def post(self, request, *args, **kwargs):
        form1 = college.StudentForm(request.POST)
        form2 = college.MocktestForm(request.POST)
        if resolve(request.path_info).url_name == 'editStudent':
            stu=Student.objects.get(id=kwargs['id2'])
            mock=MockTest1.objects.get(student=stu)
            form1=college.StudentForm(request.POST,instance=stu)
            form2=college.MocktestForm(request.POST,instance=mock)
        coll=College.objects.get(id=kwargs['id'])
        if (form1.is_valid() and form2.is_valid()):
            stu=form1.save(commit=False)
            stu.college=coll
            stu.save()
            mock=form2.save(commit=False)
            mock.total=int(mock.problem1)+int(mock.problem2)+int(mock.problem3)+int(mock.problem4)
            mock.student=stu
            mock.save()
            return redirect("students", kwargs['id'])
        form1 = college.StudentForm()
        form2 = college.MocktestForm()
        return render(
            request,
            template_name="AddStudentform.html",
            context={
                "form1": form1,
                "form2": form2
            }
        )