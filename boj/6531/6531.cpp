#include <cstdio>
#include <cstring>
char str[200 + 1];

int isSet(char *str, int left, int right);
int isElementlist(char *str, int left, int right);
int isList(char *str, int left, int right);
int isElement(char *str, int left, int right);
int isAtom(char *str, int left, int right);

int cacheSet[200][200];
int cacheElementList[200][200];
int cacheList[200][200];
int cacheElement[200][200];
int cacheAtom[200][200];

int isSet(char *str, int left, int right) {
	if (left > right) return 0; // can't be empty
	if (cacheSet[left][right] >= 0) return cacheSet[left][right];
	return cacheSet[left][right] = (str[left] == '{' && isElementlist(str, left + 1, right - 1) && str[right] == '}') ? 1 : 0;
}

int isElementlist(char *str, int left, int right) {
	if (left > right) return 1; // can be empty
	if (cacheElementList[left][right] >= 0) return cacheElementList[left][right];
	return cacheElementList[left][right] = isList(str, left, right) ? 1 : 0;
}

int isList(char *str, int left, int right) {
	if (left > right) return 0; // can't be empty
	if (cacheList[left][right] >= 0) return cacheList[left][right];
	if (isElement(str, left, right)) return cacheList[left][right] = 1;
	for (int i = left; i <= right; i++)
		if (isElement(str, left, i - 1) && str[i] == ',' && isList(str, i + 1, right)) return cacheList[left][right] = 1;
	return cacheList[left][right] = 0;
}

int isElement(char *str, int left, int right) {
	if (left > right) return 0; // can't be empty
	if (cacheElement[left][right] >= 0) return cacheElement[left][right];
	return cacheElement[left][right] = (isAtom(str, left, right) || isSet(str, left, right)) ? 1 : 0;
}

int isAtom(char *str, int left, int right) {
	if (left != right) return 0; // length should be 1
	if (cacheAtom[left][right] >= 0) return cacheAtom[left][right];
	return cacheAtom[left][right] = (str[left] == '{' || str[left] == '}' || str[left] == ',') ? 1 : 0;
}

int main(void) {

	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s\n", str);
		int len = strlen(str);

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				cacheSet[i][j] = -1;
				cacheElementList[i][j] = -1;
				cacheList[i][j] = -1;
				cacheElement[i][j] = -1;
				cacheAtom[i][j] = -1;
			}
		}

		printf("Word #%d: ", i);
		if (isSet(str, 0, len - 1)) printf("Set\n");
		else printf("No Set\n");
	}
	return 0;
}