# Tournament Winner


## Approach

- Use hashmap to store the scores of the teams.
- Keep note of maxScore and winningTeam at each iteration.

```cpp
#include <vector>
using namespace std;

string tournamentWinner(
  vector<vector<string>> competitions, vector<int> results
) {
  unordered_map<string, int> scoreMap;

  int totalMatches = competitions.size();
  int maxScore = 0;
  string winningTeam = "";

  for(int match = 0; match < totalMatches; match++){
    
    string homeTeam = competitions[match][0];
    string awayTeam = competitions[match][1];

    string winner = results[match] == 1 ? homeTeam : awayTeam;

    scoreMap[winner]++;

    if(scoreMap[winner] > maxScore){
        maxScore = scoreMap[winner];
        winningTeam = winner;
      }   
  }
  return winningTeam;
}


```


> Time Complexity: O(n)
>
> Space Complexity: O(n)