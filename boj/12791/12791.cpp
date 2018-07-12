#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector <const char *> song[2016+1];

int main(void){
	song[1967].push_back("DavidBowie");
	song[1969].push_back("SpaceOddity");
	song[1970].push_back("TheManWhoSoldTheWorld");
	song[1971].push_back("HunkyDory");
	song[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
	song[1973].push_back("AladdinSane");
	song[1973].push_back("PinUps");
	song[1974].push_back("DiamondDogs");
	song[1975].push_back("YoungAmericans");
	song[1976].push_back("StationToStation");
	song[1977].push_back("Low");
	song[1977].push_back("Heroes");
	song[1979].push_back("Lodger");
	song[1980].push_back("ScaryMonstersAndSuperCreeps");
	song[1983].push_back("LetsDance");
	song[1984].push_back("Tonight");
	song[1987].push_back("NeverLetMeDown");
	song[1993].push_back("BlackTieWhiteNoise");
	song[1995].push_back("1.Outside");
	song[1997].push_back("Earthling");
	song[1999].push_back("Hours");
	song[2002].push_back("Heathen");
	song[2003].push_back("Reality");
	song[2013].push_back("TheNextDay");
	song[2016].push_back("BlackStar");

	int q;
	scanf("%d",&q);
	while(q--){
		int s,e;
		scanf("%d %d",&s,&e);
		int songs=0;
		for(int i=s; i<=e; i++) songs+=song[i].size();
		printf("%d\n",songs);
		for(int i=s; i<=e; i++)
			for(int j=0; j<song[i].size(); j++)
				printf("%d %s\n",i,song[i][j]);
	}
	return 0;
}