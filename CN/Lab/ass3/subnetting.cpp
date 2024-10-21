#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int ip[4], subnetBits, mask[4], nHosts, nSubnets;
    cout << "Enter IP address (e.g., 192 168 1 1): ";
    for (int i = 0; i < 4; i++) cin >> ip[i];
    
    cout << "Enter number of bits for subnet: ";
    cin >> subnetBits;

    int totalBits = 32;
    int hostBits = totalBits - subnetBits;
    nHosts = pow(2, hostBits) - 2;
    nSubnets = pow(2, subnetBits - 24);

    for (int i = 0; i < 4; i++) {
        if (i < subnetBits / 8) mask[i] = 255;
        else if (i == subnetBits / 8) mask[i] = 256 - pow(2, 8 - subnetBits % 8);
        else mask[i] = 0;
    }

    cout << "Subnet Mask: ";
    for (int i = 0; i < 4; i++) cout << mask[i] << (i < 3 ? "." : "\n");

    cout << "Number of Hosts: " << nHosts << endl;
    cout << "Number of Subnets: " << nSubnets << endl;

    return 0;
}
