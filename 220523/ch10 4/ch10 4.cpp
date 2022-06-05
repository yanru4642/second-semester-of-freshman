#include <iostream>
#include <string>
using namespace std;

class Subscriber{
public:
	Subscriber();
	Subscriber(Subscriber& oldSubscriber);
	~Subscriber();

	void setName(string inName);
	string getName() { return name; }
	void setNumChannels(int inNumChannels);
	int getNumChannels() { return numChannels; }
	void setChannelList(string* inChannelList);
	string& getChannelList() { return *channelList; }

	void addChannel(string& inChannel);

	void input();
	void output();
	void reset();

	Subscriber& operator=(Subscriber& oldSubscriber);

private:
	string name;
	int numChannels;
	string* channelList;
};

Subscriber::Subscriber():name(""),numChannels(0),channelList(nullptr) {}
Subscriber::Subscriber(Subscriber& oldSubscriber){
	name = oldSubscriber.name;
	numChannels = oldSubscriber.numChannels;
	channelList = new string[numChannels];
	for (int i = 0; i < numChannels; i++){
		channelList[i] = oldSubscriber.channelList[i];
	}
}
Subscriber::~Subscriber() {
	delete [] channelList;
}

void Subscriber::setName(string inName) {
	name = inName;
}
void Subscriber::setNumChannels(int inNumChannels) {
	cout << "Warning. You're setting numChannels unilaterally. "
		<<"It might cause that numChannels not correspond to the number of channel in ChannelList." << endl;
	numChannels = inNumChannels;
}
void Subscriber::setChannelList(string* inChannelList) {
	cout << "Warning. You're setting ChannelList unilaterally. "
		<<"It might cause that numChannels not correspond to the number of channel in ChannelList." << endl;
	channelList = inChannelList;
}

void Subscriber::addChannel(string& inChannel) {
	string* oldChannelList = channelList;
	int oldNumChannels = numChannels;
	numChannels++;
	channelList = new string[numChannels];

	for (int i = 0; i < oldNumChannels; i++){
		channelList[i] = oldChannelList[i];
	}
	channelList[numChannels-1] = inChannel;

	delete [] oldChannelList;
}

void Subscriber::input() {
	string inChannel;
	cout << "Enter the subscriber's name> ";
	getline(cin, name);
	while (true){
		cout << "Enter the subscriber's channel list (enter -1 to escape)> ";
		getline(cin, inChannel);
		if (inChannel=="-1"){
			break;
		}
		addChannel(inChannel);
	}

}
void Subscriber::output() {
	cout << "-----------------------" << endl;
	cout << "Subscriber's name: " << name << endl;
	cout << "Subscribes to " << numChannels << " channel(s)." << endl;
	cout << "Channel list:" << endl;
	for (int i = 0; i < numChannels; i++){
		cout << channelList[i] << endl;
	}
	cout << "-----------------------" << endl;
}
void Subscriber::reset() {
	name = "";
	numChannels = 0;
	delete [] channelList;
	channelList = nullptr;
}

Subscriber& Subscriber::operator=(Subscriber& oldSubscriber) {
	name = oldSubscriber.name;
	numChannels = oldSubscriber.numChannels;
	delete [] channelList;
	channelList = new string[numChannels];
	for (int i = 0; i < numChannels; i++){
		channelList[i] = oldSubscriber.channelList[i];
	}
	return *this;
}

int main() {
	Subscriber a,c;

	a.input();
	cout << "a:" << endl;
	a.output();

	cout << "b: copy constructor" << endl;
	Subscriber b(a);
	b.output();

	cout << "c: operator= overloading" << endl;
	c = b;
	c.output();

	cout << "reset a:" << endl;
	a.reset();
	a.output();

    system("pause");
    return 0;
}