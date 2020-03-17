///////////////////////////////////OBSERVER///////////////////////////////////
#pragma once
#include <vector>

using std::vector;

class InputListener {
public:
	virtual void eventKey(int input) = 0;
};

class InputManager {
public:
	bool Attach(int input);
	void Detach(int input);
	void Notify(int input);

	void SetListeners(InputListener * listener);

	InputManager();

protected:
	vector<InputListener*> m_Listeners;
	vector<int> m_RegisterInput;

};
