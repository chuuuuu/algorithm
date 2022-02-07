#include <bits/stdc++.h>
using namespace std;

int getDamage(string& P){
  int n = P.size();
  int strength = 1;
  int totDamage = 0;
  for (int i=0; i<n; i++)
  {
    char c = P[i];
    if (c == 'C')
    {
      strength *= 2;
      continue;
    }

    // C == 'S'
    totDamage += strength;
  }

  return totDamage;
}

void solve()
{
  int D;
  string P;
  cin >> D >> P;

  int minDamage = 0;
  for (char c : P)
  {
    if (c == 'S')
    {
      minDamage++;
    }
  }

  if (minDamage > D)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  int ans = 0;
  while (true)
  {
    int totDamage = getDamage(P);
    if (totDamage <= D)
    {
      break;
    }

    for(int i=P.size()-1; i>=0; i--){
      if(P[i] == 'S' && P[i-1] == 'C'){
        P[i] = 'C';
        P[i-1] = 'S';
        ans++;
        break;
      }
    }
  }

  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}