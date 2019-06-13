import MySQLdb
def fun():
    cnx = MySQLdb.connect(user="root", password="123456")
    cnx=cnx.cursor()
    cnx.execute("create DATABASE tododb")
    print(cnx)
if __name__ == '__main__':
    fun()