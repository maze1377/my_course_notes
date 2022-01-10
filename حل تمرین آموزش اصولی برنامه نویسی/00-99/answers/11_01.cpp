#include<stdio.h>
#include<string.h>

struct student{
    char fname[30];
    char lname[30];
    char stNo[11];
    char grade[3];
};

void print_student(student st, FILE* file){
    fprintf(file ,"%s,%s,%s,%s",st.fname,st.lname,st.stNo,st.grade);
}

student interpret_data(char row[]){
    student temp;
    char *token = strtok(row, ",");
    strcpy(temp.fname, token);
    token = strtok(NULL, ",");
    strcpy(temp.lname, token);
    token = strtok(NULL, ",");
    strcpy(temp.stNo, token);
    token = strtok(NULL, ",");
    strcpy(temp.grade, token);
    return temp;
}

int main(){

    student students[100];
    FILE* dbfp;
    dbfp = fopen("database.txt", "r");


    if(dbfp == NULL){
        printf("Could not open database file.\n");
        return -1;
    }
    char row[80];
    rewind(dbfp);
    int i=0;
    do{
        fgets(row, 80, dbfp);
        //removing newline character
        row[strlen(row)-1] = '\0';
        students[i] = interpret_data(row);
        i++;
        if(i>=100){
            printf("Data base is too big.\n");
            break;
        }
    }while (!feof(dbfp));
    fclose(dbfp);

    FILE* inputfp;
    inputfp = fopen("input.txt","r");
    if(inputfp == NULL){
        printf("Could not open input file.\n");
        return -1;
    }

    do{
        char instruction[90];
        fgets(instruction, 90, inputfp);
        //removing newline character
        instruction[strlen(instruction)-1] = '\0';
        char upcode[7]; 
        // reading the first word of the instruction string
        sscanf(instruction, "%s", upcode);
        if(strcmp(upcode, "insert")==0){
            char data[80];
            strcpy(data, instruction + 7);
            students[i] = interpret_data(data);
            i++;
            if(i>=100){
                printf("There is not enough space.\n");
                return -1;
            }
        }else if(strcmp(upcode, "update")==0){
            char data[80];
            char id[11];
            sscanf(instruction,"update %s,",id);
            //removing comma character
            id[10] = '\0';
            strcpy(data, instruction + 18);
            student update_value = interpret_data(data);
            for (int j=0; j<i;j++){
                if(strcmp(id,students[j].stNo)==0){
                    strcpy(students[j].fname ,update_value.fname);
                    strcpy(students[j].lname ,update_value.lname);
                    strcpy(students[j].stNo ,update_value.stNo);
                    strcpy(students[j].grade ,update_value.grade);
                    break;
                }
            }
        }else if(strcmp(upcode, "delete")==0){
            char id[11];
            sscanf(instruction,"delete %s",id);
            int j;
            for ( j=0; j<i;j++){
                if(strcmp(id,students[j].stNo)==0){
                    j++;
                    for(j;j<i;j++){
                        students[j-1] = students[j];
                    }
                    i--;
                    break;
                }
            }
            
        }
    }while(!feof(inputfp));

    dbfp = fopen("database.txt", "w");
    if(dbfp == NULL){
        printf("Could not open database file.\n");
        return -1;
    }

    for(int j=0;j<i;j++){
        print_student(students[j],dbfp);
        if(j<i-1){
            fprintf(dbfp,"\n");
        }
    }

    return 0;
}