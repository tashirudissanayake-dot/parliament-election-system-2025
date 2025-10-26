#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void candidatesReg();
void showElectionResults();
void voteReg();
void admin();

int main()
{
    int type;

    for (int i = 1; i > 0; ++i)
    {
        system("cls");          // clear screen
        system("color 0B");     //  text color

        printf("\n");
        printf("==================================================\n");
        printf("        WELCOME TO ELECTION VOTING SYSTEM\n");
        printf("==================================================\n\n");
        printf(" Please select your role to continue:\n");
        printf(" -------------------------------------------------\n");
        printf("  [1]   ADMIN\n");
        printf("  [2]   CANDIDATE\n");
        printf("  [3]   VOTER\n");
        printf("  [4]   SHOW ELECTION RESULTS\n");
        printf("  [5]   EXIT\n");
        printf(" -------------------------------------------------\n");
        printf("  Enter your choice: ");
        scanf("%d", &type);
        printf("\n");

        if (type == 1)
        {
            system("cls");
            printf("\n Redirecting to Admin Panel...\n\n");
            admin();
        }
        else if (type == 2)
        {
            system("cls");
            printf("\n Redirecting to Candidate Registration...\n\n");
            candidatesReg();
        }
        else if (type == 3)
        {
            system("cls");
            printf("\n Redirecting to Voter Registration...\n\n");
            voteReg();
        }
        else if (type == 4)
        {
            system("cls");
            printf("\n Displaying Election Results...\n\n");
            showElectionResults();
        }
        else if (type == 5)
        {
            printf("\n--------------------------------------------------\n");
            printf("  Thank you for using the Election Voting System!\n");
            printf("--------------------------------------------------\n\n");
            break;
        }
        else
        {
            printf("\n  Invalid Entry! Please try again.\n\n");
            system("pause");
        }
    }

    printf("--------------------------------------------------\n");
    printf(" Program Ended Successfully.\n");
    printf("--------------------------------------------------\n");
    return 0;
}




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

    printf("Enter your name:\n\n");
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

    printf("\nEnter the your nationality(eg:-sri lanka):\n\n");
    scanf(" %[^\n]", country);

    printf("\nEnter the your district:\n\n"); // District must be "matara"
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

            int candidatecount=0; // For showing candidates registration number

            if(party=='A'||party=='a')
            {
                if(countA<5)
                {
                    printf("You choose the Sri Lanka Podujana Peramuna\n");
                    strcpy(answer, "Sri Lanka Podujana Peramuna");
                    countA++;
                    candidatecount=0+countA;
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
                    candidatecount=5+countB;
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
                    candidatecount=10+countC;
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
                    candidatecount=15+countD;
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
                    candidatecount=20+countE;
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

            FILE *nameId;
                nameId=fopen("nameId.txt","a+");//changed "a+" to "w"
                if (nameId == NULL)
                {
                    printf("Error Opening file !\n");
                    return;
                }

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
            fprintf(candidatesdata,"\nCandidate Registration Number :\t%d\n",candidatecount);
            fprintf(candidatesdata, "------------------------------------\n");
            fprintf(candidatesdata,"\n\n");
            fclose(candidatesdata);
            fprintf(nameId,"\nName :\t%s\n",name);
            fprintf(nameId,"\nCandidate Registration Number :\t%d\n",candidatecount);
            fprintf(nameId,"\nParty :\t%s\v",answer);
            fclose(nameId);
           

         printf("\n\t***You are registered***\n\t");  

         printf("\n\tYour candidate number is:%d\n\n",candidatecount);

         printf("Remaining registration slots: %d\n\n", 25 - count);

        

        
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
            if(citizenship=='n'||citizenship=='N'){
                printf("\n--- You can't vote ---\n");
            }else if(citizenship!='y'&&citizenship!='Y'){
                printf("\n--- invalid input ---\n");
            }else{    

        printf("\nIs your district Matara? (type \"y\" for yes and \"n\" for no) : ");                 //district
        scanf(" %c",&district);
            if(district=='n'||district=='N'){
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




        

        FILE *nameId=fopen("nameId.txt","r");    // r for reading
    if(nameId==NULL){
        printf("Error Opening file !\n");
        return;
    }
    char line[200];    
    while(fgets(line,sizeof(line),nameId)!=NULL){
        printf("%s", line);
    }
    
    fclose(nameId);






        printf("\nenter your party(eg:-A,B,...,X) : ");
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
                printf("\nselect a candidate : ");
                scanf("%d",&candidate);
                    if(candidate>=1&&candidate<=5){  // a's candidates are in 1-5
                    printf("\nYou selected party was : Sri Lanka Podujana Peramuna\n\nYou selected candidate was : %i\v\v",candidate);
                    
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
                    if(candidate>=6&&candidate<=10){ // b's candidates are in 6-10
                    printf("\nYou selected party was : Samagi Jana Balawegaya\n\nYou selected candidate was : %i\v\v",candidate);
                    
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
                    printf("\nYou selected party was : United National Party\n\nYou selected candidate was : %i\v\v",candidate);

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
                    printf("\nYou selected party was : National People Power\n\nYou selected candidate was : %i\v\v",candidate);
                    
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
                    printf("\nYou selected party was : Sarwajana Balaya\n\nYou selected candidate was : %i\v\v",candidate);
                    
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






void showElectionResults()
 {
    FILE *votes = fopen("votes.txt", "r");
    if (votes == NULL) {
        printf("No votes yet! Please do voting first.\n");
        return;
    }

    char line[100];
    int partyA = 0, partyB = 0, partyC = 0, partyD = 0, partyE = 0;
    int candidateVotes[26] = {0}; // Stores votes for candidates 1-25
    int totalVotes = 0;

    // Count votes for each party and candidate
    while (fgets(line, sizeof(line), votes)) {
        if (strstr(line, "Party :") != NULL) {
            char partyChar;
            if (sscanf(line, "Party : %c", &partyChar) == 1) {
                switch(partyChar) {
                    case 'A': partyA++; totalVotes++; break;
                    case 'B': partyB++; totalVotes++; break;
                    case 'C': partyC++; totalVotes++; break;
                    case 'D': partyD++; totalVotes++; break;
                    case 'E': partyE++; totalVotes++; break;
                }
            }
        }

        // Count votes for each candidate
        if (strstr(line, "Candidate :") != NULL) {
            int candidateNum;
            if (sscanf(line, "Candidate : %d", &candidateNum) == 1) {
                if (candidateNum >= 1 && candidateNum <= 25) {
                    candidateVotes[candidateNum]++;
                }
            }
        }
    }
    fclose(votes);


    printf("\n=== ELECTION RESULTS ===\n");


    if (totalVotes == 0) {
        printf("Empty Votes!\n");
        return;
    }


    printf("Party Results:\n");
    printf("A - Sri Lanka Podujana Peramuna: %d votes (%.1f%%)\n", partyA, (float)partyA/totalVotes*100);
    printf("B - Samagi Jana Balawegaya: %d votes (%.1f%%)\n", partyB, (float)partyB/totalVotes*100);
    printf("C - United National Party: %d votes (%.1f%%)\n", partyC, (float)partyC/totalVotes*100);
    printf("D - National People Power: %d votes (%.1f%%)\n", partyD, (float)partyD/totalVotes*100);
    printf("E - Sarwajana Balaya: %d votes (%.1f%%)\n", partyE, (float)partyE/totalVotes*100);


    printf("\n=== WINNING PARTY ===\n");
    int maxPartyVotes = partyA;
    char* winningParty = "A - Sri Lanka Podujana Peramuna";

    if (partyB > maxPartyVotes)
        {
        maxPartyVotes = partyB;
        winningParty = "B - Samagi Jana Balawegaya";
    }
    if (partyC > maxPartyVotes)
     {
        maxPartyVotes = partyC;
        winningParty = "C - United National Party";
    }
    if (partyD > maxPartyVotes)
     {
        maxPartyVotes = partyD;
        winningParty = "D - National People Power";
    }
    if (partyE > maxPartyVotes)
     {
        maxPartyVotes = partyE;
        winningParty = "E - Sarwajana Balaya";
    }

    // Check for equal votes party
    int partyEqualvotes = 0;
    if (partyA == maxPartyVotes)partyEqualvotes++;
    if (partyB == maxPartyVotes)partyEqualvotes++;
    if (partyC == maxPartyVotes)partyEqualvotes++;
    if (partyD == maxPartyVotes)partyEqualvotes++;
    if (partyE == maxPartyVotes)partyEqualvotes++;

    if (partyEqualvotes > 1) {
        printf("Equal votes between %d parties!\n",partyEqualvotes);
        printf("Parties with equal votes:\n");
        if (partyA == maxPartyVotes) printf("- A - Sri Lanka Podujana Peramuna\n");
        if (partyB == maxPartyVotes) printf("- B - Samagi Jana Balawegaya\n");
        if (partyC == maxPartyVotes) printf("- C - United National Party\n");
        if (partyD == maxPartyVotes) printf("- D - National People Power\n");
        if (partyE == maxPartyVotes) printf("- E - Sarwajana Balaya\n");
    } else {
        printf("Winning Party: %s\n", winningParty);
        printf("Party Votes: %d\n", maxPartyVotes);
    }


    printf("\n=== CANDIDATE RESULTS ===\n");


    printf("\nParty A - Sri Lanka Podujana Peramuna:\n"); // Party A candidates (1-5)
    int maxA = 0, winnerA = 0;
    for (int i = 1; i <= 5; i++)
        {
        printf("  Candidate %d: %d votes\n", i, candidateVotes[i]);
        if (candidateVotes[i] > maxA)

         {
            maxA = candidateVotes[i];
            winnerA = i;
        }
    }
    if (maxA > 0) printf("  Winner: Candidate %d (%d votes)\n", winnerA, maxA);


    printf("\nParty B - Samagi Jana Balawegaya:\n");    // Party B candidates (6-10)
    int maxB = 0, winnerB = 0;
    for (int i = 6; i <= 10; i++)
        {
        printf("  Candidate %d: %d votes\n", i, candidateVotes[i]);
        if (candidateVotes[i] > maxB)
            {
            maxB = candidateVotes[i];
            winnerB = i;
        }
    }
    if (maxB > 0) printf("  Winner: Candidate %d (%d votes)\n", winnerB, maxB);


    printf("\nParty C - United National Party:\n"); // Party C candidates (11-15)
    int maxC = 0, winnerC = 0;
    for (int i = 11; i <= 15; i++)
        {
        printf("  Candidate %d: %d votes\n", i, candidateVotes[i]);
        if (candidateVotes[i] > maxC)
        {
            maxC = candidateVotes[i];
            winnerC = i;
        }
    }
    if (maxC > 0) printf("  Winner: Candidate %d (%d votes)\n", winnerC, maxC);


    printf("\nParty D - National People Power:\n");   // Party D candidates (16-20)
    int maxD = 0, winnerD = 0;
    for (int i = 16; i <= 20; i++)
        {
        printf("  Candidate %d: %d votes\n", i, candidateVotes[i]);
        if (candidateVotes[i] > maxD)
            {
            maxD = candidateVotes[i];
            winnerD = i;
        }
    }
    if (maxD > 0) printf("  Winner: Candidate %d (%d votes)\n", winnerD, maxD);


    printf("\nParty E - Sarwajana Balaya:\n");    // Party E candidates (21-25)
    int maxE = 0, winnerE = 0;
    for (int i = 21; i <= 25; i++)
        {
        printf("  Candidate %d: %d votes\n", i, candidateVotes[i]);
        if (candidateVotes[i] > maxE)
            {
            maxE = candidateVotes[i];
            winnerE = i;
        }
    }
    if (maxE > 0) printf("  Winner: Candidate %d (%d votes)\n", winnerE, maxE);


    printf("\n=== WINNING CANDIDATE ===\n");
    int Winner = 0, MaxVotes = 0;
    for (int i = 1; i <= 25; i++)
        {
        if (candidateVotes[i] > MaxVotes) {
            MaxVotes = candidateVotes[i];
            Winner = i;
        }
    }

    if (MaxVotes > 0)
        {
        printf("Candidate Winner : Candidate %d\n",Winner);
        printf("Total Votes: %d\n",MaxVotes);
    } else {
        printf("No candidate received votes.\n");
    }


    FILE *voters = fopen("votersdata.txt", "r");    // Voter Count
    if (voters != NULL)
        {
        int voterCount = 0;
        while (fgets(line, sizeof(line), voters)) {
            if (strstr(line, "ID Number :") != NULL) {
                voterCount++;
            }
        }
        fclose(voters);

        printf("\n=== VOTER COUNT ===\n");
        printf("Registered Voters: %d\n", voterCount);
        printf("Total Votes: %d\n", totalVotes);

        if (voterCount > 0)
            {
            float votingPercent = (float)totalVotes / voterCount * 100;
            printf("Voting Percentage: %.1f%%\n", votingPercent);
        }
    }
}





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
            showElectionResults();//view results
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



