#include <stdio.h>
#include <string.h>

void voteReg();

int main() {

voteReg();

return 0;
}


void voteReg(){

        char id[15]; //voter's id numbers
        char vName[50];  //voter's name
        char address[100];  //voter's addresses
        char citizenship;  //voter's citizenship
        char district;  //voter's district
        int age;      //voter's age     
        char party;   //parties
        char choice;  //voter's choise
        int candidate; //candidates number
        char regId[10][15]; //id save array
        int idCount=0; //id selection
        int same; //define same ids

    for(int r=0; r<=100; r++){

        printf("\v--- ATTENTION: Please make sure to submit valid and accurate information. ---\n");

        printf("\nEnter the ID number : ");                                                              //ID
        scanf("%s",id);
        same=0;
            for(int m=0; m<idCount; m++){
                if(strcmp(regId[m],id)==0){
                    same=1;
                    break;
                }
            }
            if(same){
                printf("\n--- This ID is already registered! You cannot vote again. ---\n");
                continue;
            }
            if(strlen(id)!=10&&strlen(id)!=12){
                printf("\n--- Invalid ID ---\n");
            }else{

        printf("\nEnter the age : ");                                                                 //age
        scanf("%d",&age);
            if(age<18){
                printf("\n--- Your age is under 18. You can't vote here. ---\n");
            }else{
       
        printf("\nIs citizenship in Sri Lanka? (type \"y\" for yes and \"n\" for no) : ");              //cititionship
        scanf(" %c",&citizenship);//skip the enter using that space " c%"
            if(citizenship=='n' || citizenship=='N'){
                printf("\n--- You can't vote ---\n");
            }else if(citizenship!='y'&&citizenship!='Y'){
                printf("\n--- invalid input ---\n");
            }else{    

        printf("\nIs your district Matara? (type \"y\" for yes and \"n\" for no) : ");                 //district
        scanf(" %c",&district);
            if(district=='n' || district=='N'){
                printf("\n--- You can't vote ---\n");
            }else if(district!='y'&&district!='Y'){
                printf("\n--- invalid input ---\n");
            }else{

        printf("\nName in full : ");                                                                    //name
        scanf(" %[^\n]",vName);

        printf("\nPermanent address: ");                                                                //address
        scanf(" %[^\n]",address);

            strcpy(regId[idCount],id);
            idCount++;


        printf("--- you can vote now ---");

        printf("\n------------------------------------\n");
        printf("\tSelect a Party Name\n");
        printf("------------------------------------\n");
        printf("A: Sri Lanka Podujana Peramuna\n");
        printf("B: Samagi Jana Balawegaya\n");
        printf("C: United National Party\n");
        printf("D: National People Power\n");
        printf("E: Sarwajana Balaya\n");
        printf("X: Exit\n");
        printf("------------------------------------\n");




        

        FILE *nameId = fopen("nameId.txt", "r");  // Use "r" for reading
    if (nameId == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    
    char line[200];
    printf("\n=== READING nameId.txt FILE ===\n");
    
    while (fgets(line, sizeof(line), nameId) != NULL) {
        printf("%s", line);
    }
    
    fclose(nameId);






        printf("enter your choise(eg:-A,B,...,X) : ");
        scanf(" %c",&party);

        FILE *votersdata=fopen("votersdata.txt","a+");
        if (votersdata==NULL){
            printf("Error Opening file !\n");
            return;
        }

        FILE *votes=fopen("votes.txt","a+");
        if (votes==NULL){
            printf("Error Opening file !\n");
            return;
        }

        switch(party){
            case 'A' :
            case 'a' :     
                choice='A';
                printf("select a candidate : ");
                scanf("%d",&candidate);
                    if(candidate>=1&&candidate<=5){
                    printf("You selected party was : Sri Lanka Podujana Peramuna\nYou selected candidate was : %i",candidate);
                    
                    // Save votersdaat to votersdata.txt
                    fprintf(votersdata,"\nID Number : %s\n",id);
                    fprintf(votersdata,"Citizenship : Sri Lanka\n");
                    fprintf(votersdata,"District : Matara\n");
                    fprintf(votersdata,"Full name : %s\n",vName);
                    fprintf(votersdata,"Age : %d\n",age);
                    fprintf(votersdata,"Address : %s\n",address);
                    fprintf(votersdata,"\n-------------------------\n");            
                    // Save votes to votes.txt
                    fprintf(votes,"\nVoter ID : %s\n",id);
                    fprintf(votes,"Party : %c\n",choice);
                    fprintf(votes,"Candidate : %d\n",candidate);
                    fprintf(votes,"\n------------------------------\n");
                        
                        break;            
                    }else{
                        printf("--- invalid candidate number ---");
                        break;
                    }
                

            case 'B' :
            case 'b' : 
                choice='B';
                printf("select a candidate : ");
                scanf("%i",&candidate);
                    if(candidate>=6&&candidate<=10){
                    printf("You selected party was : Samagi Jana Balawegaya\nYou selected candidate was : %i",candidate);
                    
                    // Save votersdaat to votersdata.txt
                    fprintf(votersdata,"\nID Number : %s\n",id);
                    fprintf(votersdata,"Citizenship : Sri Lanka\n");
                    fprintf(votersdata,"District : Matara\n");
                    fprintf(votersdata,"Full name : %s\n",vName);
                    fprintf(votersdata,"Age : %d\n",age);
                    fprintf(votersdata,"Address : %s\n",address);
                    fprintf(votersdata,"\n-------------------------\n");
                    // Save votes to votes.txt
                    fprintf(votes,"\nVoter ID : %s\n",id);
                    fprintf(votes,"Party : %c\n",choice);
                    fprintf(votes,"Candidate : %d\n",candidate);
                    fprintf(votes,"\n------------------------------\n");
                    
                        break;
                    }else{
                        printf("--- invalid candidate number ---");
                        break;
                    }

            case 'C' :
            case 'c' : 
                choice='C';
                printf("select a candidate : ");
                scanf("%i",&candidate);
                    if(candidate>=11&&candidate<=15){
                    printf("You selected party was : United National Party\nYou selected candidate was : %i",candidate);

                    // Save votersdaat to votersdata.txt
                    fprintf(votersdata,"\nID Number : %s\n",id);
                    fprintf(votersdata,"Citizenship : Sri Lanka\n");
                    fprintf(votersdata,"District : Matara\n");
                    fprintf(votersdata,"Full name : %s\n",vName);
                    fprintf(votersdata,"Age : %d\n",age);
                    fprintf(votersdata,"Address : %s\n",address);
                    fprintf(votersdata,"\n-------------------------\n");
                    // Save votes to votes.txt
                    fprintf(votes,"\nVoter ID : %s\n",id);
                    fprintf(votes,"Party : %c\n",choice);
                    fprintf(votes,"Candidate : %d\n",candidate);
                    fprintf(votes,"\n------------------------------\n");

                        break;
                    }else{
                        printf("--- invalid candidate number ---");
                        break;
                    }

            case 'D' :
            case 'd' : 
                choice='D';
                printf("select a candidate : ");
                scanf("%i",&candidate);
                    if(candidate>=16&&candidate<=20){
                    printf("You selected party was : National People Power\nYou selected candidate was : %i",candidate);
                    
                    // Save votersdaat to votersdata.txt
                    fprintf(votersdata,"\nID Number : %s\n",id);
                    fprintf(votersdata,"Citizenship : Sri Lanka\n");
                    fprintf(votersdata,"District : Matara\n");
                    fprintf(votersdata,"Full name : %s\n",vName);
                    fprintf(votersdata,"Age : %d\n",age);
                    fprintf(votersdata,"Address : %s\n",address);
                    fprintf(votersdata,"\n-------------------------\n");                    
                    // Save votes to votes.txt
                    fprintf(votes,"\nVoter ID : %s\n",id);
                    fprintf(votes,"Party : %c\n",choice);
                    fprintf(votes,"Candidate : %d\n",candidate);
                    fprintf(votes,"\n------------------------------\n");
                     
                        break;
                    }else{
                        printf("--- invalid candidate number ---");
                        break;
                    }

            case 'E' :
            case 'e' : 
                choice='E';
                printf("select a candidate : ");
                scanf("%i",&candidate);
                    if(candidate>=21&&candidate<=25){
                    printf("You selected party was : Sarwajana Balaya\nYou selected candidate was : %i",candidate);
                    
                    // Save votersdaat to votersdata.txt
                    fprintf(votersdata,"\nID Number : %s\n",id);
                    fprintf(votersdata,"Citizenship : Sri Lanka\n");
                    fprintf(votersdata,"District : Matara\n");
                    fprintf(votersdata,"Full name : %s\n",vName);
                    fprintf(votersdata,"Age : %d\n",age);
                    fprintf(votersdata,"Address : %s\n",address);
                    fprintf(votersdata,"\n-------------------------\n");                   
                    // Save votes to votes.txt
                    fprintf(votes,"\nVoter ID : %s\n",id);
                    fprintf(votes,"Party : %c\n",choice);
                    fprintf(votes,"Candidate : %d\n",candidate);
                    fprintf(votes,"\n------------------------------\n");

                        break;
                    }else{
                        printf("--- invalid candidate number ---");
                        break;
                    }

            case 'X' :
            case 'x' :
                printf("\n--- you are successfully exit ---");
                break;

            default : 
                printf("\n--- Invalid input ---");        
        }

        fclose(votes);
        fclose(votersdata);

                  }
                  }   
                  }
                  }

    }

}