// truth_table.cpp
// A C++ program to analyze a logic circuit, generate its truth table,
// and derive equivalent Boolean functions in Sum of Products (SOP) and Product of Sums (POS) forms.
// Supports up to 3 inputs and 7 logic gates (AND, OR, NOT).

#include <string>
#include <iostream>
using namespace std;

struct Gate 
{
    string type;
    string inputs[4];
    int numInputs;
    string output;
};

// Function to evaluate a gate based on its type and inputs
int evaluateGate(string type, int inputs[], int numInputs) 
{
    if (type == "AND") 
    {
        for (int i = 0; i < numInputs; i++) 
        {
            if (inputs[i] == 0) return 0;
        }
        return 1;
    }
    else if (type == "OR") {
        for (int i = 0; i < numInputs; i++) 
        {
            if (inputs[i] == 1) return 1;
        }
        return 0;
    }
    else if (type == "NOT") 
    {
        return inputs[0] == 1 ? 0 : 1;
    }
    return 0;
}

// Function to find value by signal name
int findValue(string name, string inputNames[], int inputValues[], int numInputs, Gate gates[], int gateValues[], int numGates) 
{
    // Check if it's an input
    for (int i = 0; i < numInputs; i++) 
    {
        if (inputNames[i] == name) 
        {
            return inputValues[i];
        }
    }
    // Check if it's a gate output
    for (int i = 0; i < numGates; i++) 
    {
        if (gates[i].output == name) 
        {
            return gateValues[i];
        }
    }
    return 0;
}

// Function to print the truth table
void printTruthTable(int table[8][10], int rows, string headers[], int numHeaders) 
{
    cout << "\n========== TRUTH TABLE ==========\n";
    
    // Print headers
    for (int i = 0; i < numHeaders; i++) 
    {
        cout << headers[i];
        if (i < numHeaders - 1) cout << " | ";
    }
    cout << "\n";
    
    // Print separator
    for (int i = 0; i < numHeaders * 4; i++) 
    {
        cout << "-";
    }
    cout << "\n";
    
    // Print rows
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < numHeaders; j++) {
            cout << " " << table[i][j] << " ";
            if (j < numHeaders - 1) cout << "| ";
        }
        cout << "\n";
    }
    cout << "=================================\n";
}

// Function to print a minterm
void printMinterm(int index, string inputNames[], int numInputs, bool first) 
{
    if (!first) cout << " + ";
    for (int i = 0; i < numInputs; i++) 
    {
        int bit = (index >> (numInputs - 1 - i)) & 1;
        if (bit == 0) cout << inputNames[i] << "'";
        else cout << inputNames[i];
    }
}

// Function to print a maxterm
void printMaxterm(int index, string inputNames[], int numInputs, bool first) 
{
    if (!first) cout << " · ";
    cout << "(";
    for (int i = 0; i < numInputs; i++) 
    {
        int bit = (index >> (numInputs - 1 - i)) & 1;
        if (bit == 1) cout << inputNames[i] << "'";
        else cout << inputNames[i];
        if (i < numInputs - 1) cout << " + ";
    }
    cout << ")";
}

int main() {
    int numInputs;
    string inputNames[10];
    int numGates;
    Gate gates[7];
    
    cout << "========================================\n";
    cout << "   LOGIC CIRCUIT ANALYZER (C++)        \n";
    cout << "========================================\n\n";
    
    // Get number of inputs
    cout << "How many inputs does the circuit have? (1-3): ";
    cin >> numInputs;
    
    if (numInputs < 1 || numInputs > 3) 
    {
        cout << "Invalid number of inputs! Using 3 inputs.\n";
        numInputs = 3;
    }
    
    // Get input names
    cout << "\nEnter names for the inputs:\n";
    for (int i = 0; i < numInputs; i++) 
    {
        cout << "Input " << (i + 1) << ": ";
        cin >> inputNames[i];
    }
    
    // Get number of gates
    cout << "\nHow many logic gates are in the circuit? (1-7): ";
    cin >> numGates;
    
    if (numGates < 1 || numGates > 7) 
    {
        cout << "Invalid number of gates! Using 2 gates.\n";
        numGates = 2;
    }
    
    // Configure each gate
    cout << "\nAvailable gate types: AND, OR, NOT\n\n";
    
    for (int i = 0; i < numGates; i++) 
    {
        cout << "--- Gate " << (i + 1) << " Configuration ---\n";
        
        // Gate type
        cout << "Enter gate type: ";
        cin >> gates[i].type;
        
        // Convert to uppercase
        for (int j = 0; j < gates[i].type.length(); j++) 
        {
            if (gates[i].type[j] >= 'a' && gates[i].type[j] <= 'z') 
            {
                gates[i].type[j] = gates[i].type[j] - 'a' + 'A';
            }
        }
        
        // Number of inputs
        if (gates[i].type == "NOT") 
        {
            gates[i].numInputs = 1;
        } 
        else 
        {
            cout << "Number of inputs for this gate (2-4): ";
            cin >> gates[i].numInputs;
            if (gates[i].numInputs < 2) gates[i].numInputs = 2;
            if (gates[i].numInputs > 4) gates[i].numInputs = 4;
        }
        
        // Get inputs
        cout << "Available signals: ";
        for (int j = 0; j < numInputs; j++) 
        {
            cout << inputNames[j] << " ";
        }
        for (int j = 0; j < i; j++) 
        {
            cout << gates[j].output << " ";
        }
        cout << "\n";
        
        for (int j = 0; j < gates[i].numInputs; j++) 
        {
            cout << "Input " << (j + 1) << " signal: ";
            cin >> gates[i].inputs[j];
        }
        
        // Output name
        cout << "Output signal name: ";
        cin >> gates[i].output;
        
        cout << "\n";
    }
    
    // Generate truth table
    int rows = 1;
    for (int i = 0; i < numInputs; i++) 
    {
        rows *= 2;
    }
    
    int truthTable[8][10]; // Max 3 inputs + 7 gates = 10 columns
    int minterms[64];
    int maxterms[64];
    int mintermCount = 0;
    int maxtermCount = 0;
    
    // Headers for truth table
    string headers[10];
    int headerCount = 0;
    for (int i = 0; i < numInputs; i++) 
    {
        headers[headerCount++] = inputNames[i];
    }
    for (int i = 0; i < numGates; i++) 
    {
        headers[headerCount++] = gates[i].output;
    }
    
    // Generate each row
    for (int row = 0; row < rows; row++) 
    {
        int inputValues[10];
        int gateValues[20];
        
        // Generate input combinations
        for (int i = 0; i < numInputs; i++) 
        {
            inputValues[i] = (row >> (numInputs - 1 - i)) & 1;
            truthTable[row][i] = inputValues[i];
        }
        
        // Evaluate gates
        for (int g = 0; g < numGates; g++) 
        {
            int gateInputs[4];
            
            // Get input values
            for (int i = 0; i < gates[g].numInputs; i++) 
            {
                gateInputs[i] = findValue(gates[g].inputs[i], inputNames, inputValues, 
                                          numInputs, gates, gateValues, g);
            }
            
            // Evaluate gate
            gateValues[g] = evaluateGate(gates[g].type, gateInputs, gates[g].numInputs);
            truthTable[row][numInputs + g] = gateValues[g];
        }
        
        // Record minterms and maxterms
        int finalOutput = truthTable[row][headerCount - 1];
        if (finalOutput == 1) 
        {
            minterms[mintermCount++] = row;
        } 
        else 
        {
            maxterms[maxtermCount++] = row;
        }
    }
    
    // Print truth table
    printTruthTable(truthTable, rows, headers, headerCount);
    
    // Print equivalent functions
    cout << "\n========== EQUIVALENT BOOLEAN FUNCTIONS ==========\n\n";
    
    // Sum of Products (SOP)
    cout << "Sum of Products (SOP):\n";
    cout << "F = ";
    if (mintermCount == 0) 
    {
        cout << "0";
    } 
    else if (mintermCount == rows) 
    {
        cout << "1";
    } 
    else 
    {
        for (int i = 0; i < mintermCount; i++) 
        {
            printMinterm(minterms[i], inputNames, numInputs, i == 0);
        }
    }
    cout << "\n\n";
    
    // Product of Sums (POS)
    cout << "Product of Sums (POS):\n";
    cout << "F = ";
    if (maxtermCount == 0) 
    {
        cout << "1";
    } 
    else if (maxtermCount == rows) 
    {
        cout << "0";
    } 
    else 
    {
        for (int i = 0; i < maxtermCount; i++) 
        {
            printMaxterm(maxterms[i], inputNames, numInputs, i == 0);
        }
    }
    cout << "\n\n";
    
    cout << "==================================================\n\n";
    
    // Legend
    cout << "Legend:\n";
    cout << "  A' = NOT A (complement)\n";
    cout << "  +  = OR operation\n";
    cout << "  ·  = AND operation\n";
    cout << "  SOP: Sum of minterms (OR of AND terms)\n";
    cout << "  POS: Product of maxterms (AND of OR terms)\n";
    
    return 0;
}