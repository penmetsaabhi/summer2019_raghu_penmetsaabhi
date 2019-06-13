from django import  forms
from todoapp.models import ToDoList,ToDoItem
class todoListForm(forms.ModelForm):
    class Meta:
        model=ToDoList
        exclude=['id','datetime']
        fields=['name']
class todoItemForm(forms.ModelForm):
    class Meta:
        model=ToDoItem
        exclude=['id','todolist']
        widgets={
            'description':forms.TextInput(attrs={'class' : 'input','placeholder':'description'}),
            'due_date':forms.DateInput(attrs={'class':'input','type':'date','placeholder':'DATE'})
        }