#include <stdio.h>
#include <string.h>

void showElectionResults();

int main() {
    printf("=== ELECTION RESULTS SYSTEM ===\n");
    showElectionResults();

    return 0;
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
