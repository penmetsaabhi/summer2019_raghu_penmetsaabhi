from django import  forms
from onlineapp.models import College,Student,MockTest1
class CollegeForm(forms.ModelForm):
    class Meta:
        model=College
        exclude=['id']
        fields=['name','location','acronym','contact']
        # widgets={
        #     'name':forms.CharField(max_length=168),
        #     'location':forms.CharField(max_length=168),
        #     'acronym':forms.CharField(max_length=168),
        #     'contact':forms.EmailField()
        # }
class StudentForm(forms.ModelForm):
    class Meta:
        model=Student
        exclude=['id','college']
        fields=['name','email','db_folder','dropped_out']
class MocktestForm(forms.ModelForm):
    class Meta:
        model=MockTest1
        exclude=['total','student']
        fields=['problem1','problem2','problem3','problem4']