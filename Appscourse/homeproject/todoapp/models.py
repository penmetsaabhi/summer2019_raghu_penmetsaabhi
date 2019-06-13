from django.db import models

# Create your models here.
class ToDoList(models.Model):
    name = models.CharField(max_length=128)
    datetime=models.DateTimeField(auto_now_add=True)
    def __str__(self):
        return self.name
class ToDoItem(models.Model):
    description=models.TextField()
    due_date=models.DateField(null=True)
    completed = models.BooleanField(default=False)
    todolist = models.ForeignKey(ToDoList, on_delete=models.CASCADE)
    def __str__(self):
        return self.description