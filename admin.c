#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <calculation.c>
void candidatesReg(); //define candidates register function
void admin();
int main()
{
	admin(); // call admin function
	return 0;
}

//create admin function
void admin()
{
	char Aname[50]; // store admin name
	char Apwd[15]; // store admin password
	char fileName[50], filepwd[15], line[100], fileNameBuffer[50]; // file arrays
	int j; //condition veriable


	printf("\nEnter your name\n\n");
	scanf("%s",Aname); //input admin name

	printf("\nEnter the Password:\n\n");
    scanf("%s",Apwd); //input admin nic

    FILE *admindata; //create file pointer to admin file
    admindata=fopen("admindata.txt","a+"); // open admin date file
    if (admindata == NULL) {
        printf("Admin data file does not exist!\n");
        return;
    }

    int found = 0;
    while (fgets(line, sizeof(line), admindata)) 
    {
       
        if (sscanf(line, "Apwd: %s", filepwd) == 1)
         {
            if (strcmp(filepwd, Apwd) == 0)
             {
                found = 1;
                break;
            }
        }
    }

    fclose(admindata);

    if (found) 
    {
        printf("\nLogin successful! Welcome Admin.\n\n");    


        printf("\n-------------------------------------\n");
        printf("         ELECTION SYSTEM             ");
        printf("\n-------------------------------------\n");

        printf("\n1-Candidates Data");
        printf("\n2-Voters Data");
        printf("\n3-Etection  Results");
        printf("\n4-Exit\n");

        printf("\nChoose what you want :- ");
        scanf("%d",&j);

        if(j==1)
        {

            
	        FILE *candidatesdata;
	            candidatesdata=fopen("candidatesdata.txt","a+");//changed "a+" to "w"
	            if (candidatesdata == NULL)
	            {
	                printf("Error Opening file !\n");
	                return;
	            }

	         //Option to view all candidates
			    char viewcan;
			    printf("\n\nWould you like to view all registered candidates? (Y/N): ");
			    scanf(" %c", &viewcan);

			    if (viewcan == 'Y' || viewcan == 'y')
			    {
			        FILE *filecan = fopen("candidatesdata.txt", "r");
			        if (filecan)
			        {
			            char line[200];
			            printf("\n--- Registered Candidates ---\n\n");
			            while (fgets(line, sizeof(line), filecan))
			            {
			                printf("%s", line);
			            }
			            fclose(filecan);
			        }
			        else
			        {
			            printf("Error reading file.\n");
			        }
			    }

			    printf("\nThank you for using the registration system!\n");
	    }

	    else if(j==2)
	    {
	    	
	        FILE *votersdata;
	            votersdata=fopen("votersdata.txt","a+");//changed "a+" to "w"
	            if (votersdata == NULL)
	            {
	                printf("Error Opening file !\n");
	                return;
	            }

	         //Option to view all voters
			    char viewvoter;
			    printf("\n\nWould you like to view all registered voters? (Y/N): ");
			    scanf(" %c", &viewvoter);

			    if (viewvoter == 'Y' || viewvoter== 'y')
			    {
			        FILE *filevot = fopen("votersdata.txt", "r");
			        if (filevot)
			        {
			            char line[300];
			            printf("\n--- Registered voters ---\n\n");
			            while (fgets(line, sizeof(line), filevot))
			            {
			                printf("%s", line);
			            }
			            fclose(filevot);
			        }
			        else
			        {
			            printf("Error reading file.\n");
			        }
			    }

			    printf("\nThank you for using the registration system!\n");
	    }

	    else if(j==3)
	    {
	    	void showElectionResults();//view results
	    }

	    else if(j==4)
	    {
	    	printf("Exited the system...\n");// exit the system
	    }

	    else
	    {
	    	printf("wrong selection");
	    }

    } 
    else {
        printf("\nPassword is wrong. Access denied.\n");
    }
}
