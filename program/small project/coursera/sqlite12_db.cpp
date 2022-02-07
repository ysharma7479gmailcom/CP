#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include<bits/stdc++.h>
using namespace std;


class tree
{ 
public:	
	void write_rec(); 
	void search_rec();   
	void show_rec(string id);
};
tree A;	

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void tree::write_rec()
{
	cout<<"\nEnter first person information: "<<endl;
	
	string t1,t2;
	cout<<"\nEnter person Name:";
	
	cin>>t1;
	cout<<"\nEnter person britecamp_id:";
	cin>>t2;

	
	cout<<"\n.................................."<<endl;
	
	cout<<"\nEnter second person information: "<<endl;
	
	string x1,x2;
		cout<<"\nEnter person Name:";
		cin>>x1;
		cout<<"\nEnter person britecamp_id:";
		cin>>x2;
	cout<<"\n.................................."<<endl;
	
	cout<<"\nEnter the relation between them: ";
	string relation;
	cin>>relation;
		
	sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("family_tree.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return ;
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "INSERT INTO Table1 (ID1,NAME1,ID2,NAME2,RELATION) "  \
         "VALUES (t2, t1, x2, x1, relation ); ";
         

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Records created successfully\n");
   }
   sqlite3_close(db);
   
	cout<<"\n.........data stored........"<<endl;
	return;	
}

void tree::show_rec(string id)
{
	
}

void tree::search_rec()
{
	cout<<"\nEnter person Britecamp-ID: ";
	string search_id;
	cin>>search_id;

}
void create_database()
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;

   /* Open database */
   rc = sqlite3_open("family_tree.db", &db);
   
   /* Create SQL statement */
   sql = "CREATE TABLE Table1("  \
      "ID1 TEXT PRIMARY KEY     NOT NULL," \
      "NAME1           TEXT    NOT NULL," \
      "ID2            TEXT    NOT NULL," \
      "NAME2           TEXT    NOT NULL," \
       "RELATION       TEXT);"; 
    
     /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
   return ;
}
int main()
{
	cout<<"asd";
 	create_database();
	cout<<"asd";
    tree A;
	int choice;
    string temp;
   
    while(true)
	{
	   cout<<"***FAMILY TREE APPLICATION FOR KIDS***"<<endl;
        cout<<"Select one option below ";
        cout<<"\n\t1-->Add record to file";
        cout<<"\n\t2-->Search Record from file"<<endl;
        cin>>temp;
        if(temp.size()==1 && (temp=="1" || temp=="2"))
    {
	   if(temp=="1")choice=1;else choice=2;
        switch(choice)
        {
        case 1:
            A.write_rec();
            break;
        case 2:
            A.search_rec();
            break;
        }
    }
    else cout<<"\nEnter incorrect choice"<<endl;
       	cout<<endl;
        system("pause");
        system("cls");
	}
    system("pause");
    return 0;
}
//
//static int callback1(void *NotUsed, int argc, char **argv, char **azColName) {
//   int i;
//   for(i = 0; i<argc; i++) {
//      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//   }
//   printf("\n");
//   return 0;
//}
//
//static int callback(void *data, int argc, char **argv, char **azColName){
//   int i;
//   fprintf(stderr, "%s: ", (const char*)data);
//   
//   for(i = 0; i<argc; i++){
//      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//   }
//   
//   printf("\n");
//   return 0;
//}
//
//int main(int argc, char* argv[]) {
//   sqlite3 *db;
//   char *zErrMsg = 0;
//   int rc;
//   char *sql;
//   const char* data = "Callback function called";
//
//
//   /* Open database */
//   rc = sqlite3_open("test.db", &db);
//   
//   if( rc ) {
//      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//      return(0);
//   } else {
//      fprintf(stdout, "Opened database successfully\n");
//   }
//
//  sql = "UPDATE COMPANY set SALARY = 2000.00 where AGE>30; " 
//         "SELECT * from COMPANY";
//
//   /* Execute SQL statement */
//   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
//   
//   if( rc != SQLITE_OK ) {
//      fprintf(stderr, "SQL error: %s\n", zErrMsg);
//      sqlite3_free(zErrMsg);
//   } else {
//      fprintf(stdout, "Operation done successfully\n");
//   }
//   sqlite3_close(db);
//   return 0;
//}
