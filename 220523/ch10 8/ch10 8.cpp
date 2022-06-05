#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class Television {
public:
    Television();
    Television(const Television& oldTelevision);
    Television(const string& inDisplayType, double inDimension, string* inConnectivitySupport);
    ~Television();
    Television& operator=(const Television& oldTelevision);

    void setDisplayType(const string& inDisplayType);
    void setDimension(double inDimension);
    void setConnectivitySupport(string* inConnectivitySupport);
    const string& getDisplayType() { return displayType; }
    const double getDimension() { return dimension; }
    string* getConnectivitySupport(int& num) { num = numConnectivitySupport; return connectivitySupport; }

    void addConnectivitySupport(string newSupport);

    void output();
private:
    string displayType;
    double dimension;
    string* connectivitySupport;
    int numConnectivitySupport;
};

Television::Television()
    :displayType(""),dimension(0.0),connectivitySupport(nullptr),numConnectivitySupport(0) {}
Television::Television(const Television& oldTelevision) {
    displayType = oldTelevision.displayType;
    dimension = oldTelevision.dimension;
    numConnectivitySupport = oldTelevision.numConnectivitySupport;
    delete[] connectivitySupport;
    connectivitySupport = new string[numConnectivitySupport];
    for (int i = 0; i < numConnectivitySupport; i++){
        connectivitySupport[i] = oldTelevision.connectivitySupport[i];
    }
}
Television::Television(const string& inDisplayType, double inDimension, string* inConnectivitySupport) {
    displayType = inDisplayType;
    dimension = inDimension;

    numConnectivitySupport = 1;
    connectivitySupport = new string[1];
    connectivitySupport[0] = inConnectivitySupport[0];
}
Television::~Television() {
    delete [] connectivitySupport;
    connectivitySupport = nullptr;
}
Television& Television::operator=(const Television& oldTelevision) {
    displayType = oldTelevision.displayType;
    dimension = oldTelevision.dimension;
    numConnectivitySupport = oldTelevision.numConnectivitySupport;
    connectivitySupport = new string[numConnectivitySupport];
    for (int i = 0; i < numConnectivitySupport; i++) {
        connectivitySupport[i] = oldTelevision.connectivitySupport[i];
    }
    return *this;
}

void Television::setDisplayType(const string& inDisplayType){
    displayType = inDisplayType;
}
void Television::setDimension(double inDimension){
    dimension = inDimension;
}
void Television::setConnectivitySupport(string* inConnectivitySupport){
    connectivitySupport = inConnectivitySupport;
}

void Television::addConnectivitySupport(string newSupport){
    string* oldConnectivitySupport = connectivitySupport;
    int oldNumConnectivitySupport = numConnectivitySupport;

    numConnectivitySupport++;
    connectivitySupport = new string[numConnectivitySupport];

    for (int i = 0; i < oldNumConnectivitySupport; i++){
        connectivitySupport[i] = oldConnectivitySupport[i];
    }
    connectivitySupport[numConnectivitySupport - 1] = newSupport;

    delete [] oldConnectivitySupport;
    oldConnectivitySupport = nullptr;
}

void Television::output() {
    cout << "-------------------------" << endl;
    cout << "Display type: " << displayType << endl;
    cout << "Dimension: " << dimension << endl;
    cout << "Connectivity support: " << endl;
    for (int i = 0; i < numConnectivitySupport; i++) {
        cout << connectivitySupport[i] << endl;
    }
    cout << "-------------------------" << endl;
}

int main() {
    Television* televisionList;
    int numTelevisionList = 0;
    //constructor
    string inDisplayType;
    double inDimension;
    string* inConnectivitySupport = nullptr;
    string inSupport;
    //mutate TV
    string cmdTV;
    string cmdItem;
    string cmdSupport;
    string* receiveConnectivitySupport = nullptr;
    int receiveNumConnectivitySupport;

    //create television objects
    cout << "Enter the amount of television> ";
    cin >> numTelevisionList;
    if (numTelevisionList < 1) {
        cout << "Error. The amount of television should >=1" << endl;
        exit(1);
    }
    televisionList = new Television[numTelevisionList];
    //input the first television
    cout << "Enter displayType> ";
    cin >> inDisplayType;
    cout << "Enter dimension> ";
    cin >> inDimension;
    cout << "Enter connectivitySupport> ";
    cin.ignore();
    getline(cin, inSupport);
    inConnectivitySupport = new string[1];
    inConnectivitySupport[0] = inSupport;
    /*
    Television original(inDisplayType, inDimension, inConnectivitySupport);
    original.output();
    */
    /*
    Television* original;
    original = new Television(inDisplayType, inDimension, inConnectivitySupport);
    original->output();
    */
    Television original;
    original =  Television(inDisplayType, inDimension, inConnectivitySupport);
    
    while (true){
        cout << "Enter connectivitySupport (enter -1 to escape)> ";
        getline(cin, inSupport);
        if (inSupport=="-1"){
            break;
        }
        original.addConnectivitySupport(inSupport);
    }
    
    //copy all television from the original
    for (int i = 0; i < numTelevisionList; i++){
        televisionList[i] = original;
    }
    //show all television
    cout << "===============================" << endl;
    for (int i = 0; i < numTelevisionList; i++){
        cout << "Television " << i << endl;
        televisionList[i].output();
    }
    cout << "===============================" << endl;
    while (true){
        //change TV
        cout << "Enter which TV you want to change(ex. enter 0 to change Television 0)(enter -1 to escape)> " << endl;
        getline(cin, cmdTV);
        if (cmdTV == "-1") {
            break;
        }
        for (int i = 0; i < cmdTV.size(); i++) {
            if (!isdigit(cmdTV[i])) {
                cout << "Invalid TV number" << endl;
                exit(1);
            }
        }
        if (stoi(cmdTV) < 0 || stoi(cmdTV) >= numTelevisionList) {
            cout << "Invalid TV number" << endl;
            exit(1);
        }
        cout << "Changing television " << stoi(cmdTV) << "..." << endl;
        cout << "Enter which item you want to change in television " << stoi(cmdTV) << endl;
        cout << "(Enter dis): change Display" << endl;
        cout << "(Enter dim): change Dimension" << endl;
        receiveConnectivitySupport = televisionList[stoi(cmdTV)].getConnectivitySupport(receiveNumConnectivitySupport);
        for (int i = 0; i < receiveNumConnectivitySupport; i++) {
            cout << "(Enter " << i << "): change ConnectivitySupport \"" << receiveConnectivitySupport[i] << "\"" << endl;
        }
        getline(cin, cmdItem);
        if (cmdItem == "dis") {
            //change display
            cout << "Enter new display type> ";
            getline(cin, cmdItem);
            televisionList[stoi(cmdTV)].setDisplayType(cmdItem);
        }
        else if (cmdItem == "dim") {
            //change dimension
            cout << "Enter new dimension> ";
            getline(cin, cmdItem);
            for (int i = 0; i < cmdItem.size(); i++) {
                if (!isdigit(cmdItem[i]) && cmdItem[i] != '.') {
                    cout << "dimension should be a number" << endl;
                    exit(1);
                }
            }
            televisionList[stoi(cmdTV)].setDimension(stod(cmdItem));
        }
        else {
            //change connectivity support
            for (int i = 0; i < cmdItem.size(); i++) {
                if (!isdigit(cmdItem[i])) {
                    cout << "Invalid Index" << endl;
                    exit(1);
                }
            }
            if (stoi(cmdItem) < 0 || stoi(cmdItem) >= receiveNumConnectivitySupport) {
                cout << "Invalid Index" << endl;
                exit(1);
            }
            cout << "Enter new support> ";
            getline(cin, cmdSupport);
            receiveConnectivitySupport[stoi(cmdItem)] = cmdSupport;
            televisionList[stoi(cmdTV)].setConnectivitySupport(receiveConnectivitySupport);
        }
        //show all television
        cout << "===============================" << endl;
        for (int i = 0; i < numTelevisionList; i++) {
            cout << "Television " << i << endl;
            televisionList[i].output();
        }
        cout << "===============================" << endl;
    }
    delete [] inConnectivitySupport;
    inConnectivitySupport = nullptr;
    delete [] receiveConnectivitySupport;
    receiveConnectivitySupport = nullptr;


    system("pause");
    return 0;
}