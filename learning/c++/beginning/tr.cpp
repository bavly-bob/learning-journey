#include <iostream>
using namespace std;

int main()
{
    const int MAX_INPUTS = 3;
    const int MAX_GATES  = 7;

    int numInputs, numGates;

    cout << "Enter number of inputs (1 to 3): ";
    cin >> numInputs;

    if (numInputs < 1 || numInputs > MAX_INPUTS)
    {
        cout << "Invalid number of inputs.\n";
        return 0;
    }

    cout << "Enter number of logic gates (1 to 7): ";
    cin >> numGates;

    if (numGates < 1 || numGates > MAX_GATES)
    {
        cout << "Invalid number of gates.\n";
        return 0;
    }

    // gate type: 1=AND, 2=OR, 3=NOT
    int gateType[MAX_GATES];
    int gateIn1[MAX_GATES];
    int gateIn2[MAX_GATES];

    cout << "\nInput indexes:\n";
    cout << "A=0, B=1, C=2\n";
    cout << "Gate outputs start from index 3\n\n";

    for (int i = 0; i < numGates; i++)
    {
        cout << "Gate " << i + 1 << " type (1=AND, 2=OR, 3=NOT): ";
        cin >> gateType[i];

        cout << "First input index: ";
        cin >> gateIn1[i];

        if (gateType[i] != 3)
        {
            cout << "Second input index: ";
            cin >> gateIn2[i];
        }
    }

    cout << "\nTruth Table:\n";

    int rows = 1;
    for (int i = 0; i < numInputs; i++)
        rows *= 2;

    // header
    for (int i = 0; i < numInputs; i++)
        cout << char('A' + i) << " ";
    cout << "| Output\n";

    for (int r = 0; r < rows; r++)
    {
        int value[10]; // 3 inputs + 7 gates = 10 max

        // input values
        for (int i = 0; i < numInputs; i++)
        {
            value[i] = (r >> (numInputs - 1 - i)) & 1;
            cout << value[i] << " ";
        }

        // gate evaluation
        for (int g = 0; g < numGates; g++)
        {
            if (gateType[g] == 1) // AND
                value[numInputs + g] =   value[gateIn1[g]] && value[gateIn2[g]];
            
            else if (gateType[g] == 2) // OR
                value[numInputs + g] =   value[gateIn1[g]] || value[gateIn2[g]];
            
            else // NOT
                value[numInputs + g] =   !value[gateIn1[g]];
        }

        cout << "| " << value[numInputs + numGates - 1] << endl;
    }

    cout << "\nEquivalent Boolean Function:\n";
    cout << "Output = ";

    for (int g = 0; g < numGates; g++)
    {
        if (g > 0) cout << " -> ";

        if (gateType[g] == 1)
            cout << "(X" << gateIn1[g] << " AND X" << gateIn2[g] << ")";
        
        else if (gateType[g] == 2)
            cout << "(X" << gateIn1[g] << " OR X" << gateIn2[g] << ")";
        
        else
            cout << "(NOT X" << gateIn1[g] << ")";
    }

    cout << endl;
    return 0;
}
