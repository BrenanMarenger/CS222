//Brenan Marengers
#pragma once

class Bracket {
public:
	Bracket() { kind = NULL; position = NULL; }
	Bracket(char k, int p) { kind = k; position = p; }
	bool matches(char c);
	int getPos() { return position; }
private:
	char kind;
	int position; 
};

bool Bracket::matches(char c) {
	if( (kind =='(' && c ==')') || (kind =='[' && c ==']') ) { 
		return true;
} else {
 return false;
	}
}