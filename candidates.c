#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void candidatesReg()
{

    char name[30];           //candidate names
    int age;                 //candidate age
    char country[10];        //candidate country
    char district[10];           //candidate citizenship
    char party;              //if condition checking variable
    char nic[15];            //candidate id number
    char answer[80];         //txt file save  --->  candidate party
    char prevNICs[25][15];    // store previous NICs to prevent duplicates
    int count=0,countA=0,countB=0,countC=0,countD=0,countE=0;

    while(count<25)
        
    {
    //system("cls");   // Clear screen
   
    printf("\n====================================\n");
    printf("     CANDIDATE REGISTRATION FORM\n");
    printf("====================================\n");

    printf("Enter your name(eg:-mahinda_rajapaksha):\n\n");
    scanf(" %[^\n]", name);

    printf("\nEnter your national id card number:\n\n");
    scanf("%s",nic);


    
    

    if(strlen(nic)!=10 && strlen(nic)!=12)          //checking nic validation
    {
        printf("\n ---Invalid ID Number---\n");
        system("pause");
        continue;
    }

    //Duplicate NIC check
        int duplicate = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(prevNICs[i], nic) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) {
            printf("\n--- This NIC is already registered ---\n");
            continue;
        }

    printf("\nEnter the your nationality(eg:-sri_lanka):\n\n");
    scanf(" %[^\n]", country);

    printf("\nEnter the your district:\n\n");
    scanf(" %[^\n]", district);



    if(strcmp(district, "matara") != 0 && strcmp(district, "MATARA") != 0 && strcmp(district, "Matara") != 0)                 //cheking citizenship
    {
        printf("\n--- Your district is not eligible for registration ---\n");
        system("pause");
        continue;

    }


    printf("\nEnter your age:\n\n");
    scanf("%d",&age);



        if(age<18)
        {
            printf("\nYou cannot register here (must be 18 or older)\n");
            continue;

        }


            printf("------------------------------------\n");
            printf("\tParty Names\n");
            printf("------------------------------------\n");

            printf("A: Sri Lanka Podujana Peramuna\n");
            printf("B: Samagi Jana Balawegaya\n");
            printf("C: United National Party\n");
            printf("D: National People Power\n");
            printf("E: Sarwajana Balaya\n");
            printf("X: Exit\n");
            printf("------------------------------------\n");



            printf("Enter your party name(eg:-A-E) :- ");
            scanf(" %c",&party);
            printf("\n");


            if(party=='A'||party=='a')
            {
                if(countA<5)
                {
                    printf("You choose the Sri Lanka Podujana Peramuna\n");
                    strcpy(answer, "Sri Lanka Podujana Peramuna");
                    countA++;
                }
                else
                {
                    printf("You can not register this party,This party has full of members\n\n");
                    continue;
                }

            }         
            else if(party=='B'||party=='b')
            {
                if(countB<5)
                {
                    printf("You choose the Samagi Jana Balawegaya\n");
                    strcpy(answer, "Samagi Jana Balawegaya");
                    countB++;
                }
                else
                {
                    printf("You can not register this party,This party has full of members\n\n");
                    continue;
                }


            }
            else if(party=='C'||party=='c')
            {
                if(countC<5)
                {
                    printf("You choose the United National Party\n");
                    strcpy(answer, "United National Party");
                    countC++;
                }
                else
                {
                    printf("You can not register this party,This party has full of members\n\n");
                    continue;
                }

            }
            else if(party=='D'||party=='d')
            {
                if(countD<5)
                {
                    printf("You choose the National People Power\n");
                    strcpy(answer, "National People Power");
                    countD++;
                }
                else
                {
                    printf("You can not register this party,This party has full of members\n\n");
                    continue;
                }

            }
            else if(party=='E'||party=='e')
            {
                if(countE<5)
                {
                    printf("You choose the Sarwajana Balaya\n");
                    strcpy(answer, "Sarwajana Balaya");
                    countE++;
                }
                else
                {
                    printf("You can not register this party,This party has full of members\n\n");
                    continue;
                }

            }
            else if(party=='X'||party=='x')
            {
                char confirm;
                printf("Are you sure you want to exit? (Y/N): ");
                scanf(" %c", &confirm);

                if(confirm == 'Y' || confirm == 'y') {
                 printf("--- You have exited ---\n");
                 break;
                 }
                  else {
                      continue;
                 }
                
            }
           
            else
            {
                printf("---This is not a registerd party---\n");
                continue;
            }



            //Store NIC after successful registration
            strcpy(prevNICs[count], nic);

            /*FILE *clearFile = fopen("candidatesdata.txt", "w");
            fclose(clearFile);*/


            FILE *candidatesdata;
            candidatesdata=fopen("candidatesdata.txt","a+");//changed "a+" to "w"
            if (candidatesdata == NULL)
            {
                printf("Error Opening file !\n");
                return;
            }
            count++;
            fprintf(candidatesdata, "------------------------------------\n");
            fprintf(candidatesdata, "      ***CANDIDATES DETAILS***\n");
            fprintf(candidatesdata, "------------------------------------\n");
            fprintf(candidatesdata,"\nName :\t%s\n",name);
            fprintf(candidatesdata,"\nNIC :\t%s\n",nic);
            fprintf(candidatesdata,"\nCountry :%s\n",country); 
            fprintf(candidatesdata,"\ndistrict :%s\n",district);
            fprintf(candidatesdata,"\nAge :\t%d\n",age);
            fprintf(candidatesdata,"\nParty :\t%s\n",answer);
            fprintf(candidatesdata,"\nCandidate Registration Number :\t%d\n",count);
            fprintf(candidatesdata, "------------------------------------\n");
            fprintf(candidatesdata,"\n\n");
            fclose(candidatesdata);
           

         printf("\n\t***You are registered***\n\t");  

         printf("\n\tYour candidate number is:%d\n\n",count);

         printf("Remaining registration slots: %d\n\n", 25 - count);

        

        /*FILE *file = fopen("candidatesdata.txt", "r");
        if (file) {
             char line[200];
             printf("\n--- Registered Candidates ---\n");
             while (fgets(line, sizeof(line), file)) {
                  printf("%s", line);
        }
        fclose(file);
    }*/
//system("cls");
printf("             Final Party Summary\n");
printf("----------------------------------------------\n");
printf("A: Sri Lanka Podujana Peramuna   - %d members\n", countA);
printf("B: Samagi Jana Balawegaya        - %d members\n", countB);
printf("C: United National Party         - %d members\n", countC);
printf("D: National People Power         - %d members\n", countD);
printf("E: Sarwajana Balaya              - %d members\n", countE);
printf("----------------------------------------------");

//Option to view all candidates
    char view;
    printf("\n\nWould you like to view all registered candidates? (Y/N): ");
    scanf(" %c", &view);

    if (view == 'Y' || view == 'y')
    {
        FILE *file = fopen("candidatesdata.txt", "r");
        if (file)
        {
            char line[200];
            printf("\n--- Registered Candidates ---\n\n");
            while (fgets(line, sizeof(line), file))
            {
                printf("%s", line);
            }
            fclose(file);
        }
        else
        {
            printf("Error reading file.\n");
        }
    }

    printf("\nThank you for using the registration system!\n");

system("pause");

}
if(count==25)
{
    printf("\n---Only 25 members can register here---\n");  
}

printf("\n--- Registration Closed ---\n");

}

int main()
{
    candidatesReg();
    return 0;
}
