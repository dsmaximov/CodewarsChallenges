//We need you to implement a method of receiving commands over a network, processing the informationand responding.
//
//Our device will send a single packet to you containing dataand an instruction which you must perform before returning your reply.
//
//To keep things simple, we will be passing a single "packet" as a string.Each "byte" contained in the packet is represented by 4 chars.
//
//One packet is structured as below :
//
//Header  Instruction   Data1    Data2   Footer
//------   ------       ------   ------  ------
//H1H1     0F12         0012     0008    F4F4
//------   ------       ------   ------  ------
//
//The string received in this case would be - "H1H10F1200120008F4F4"
//
//Instruction: The calculation you should perform, always one of the below.
//    0F12 = Addition
//    B7A2 = Subtraction
//    C3D9 = Multiplication
//    FFFF = This instruction code should be used to identify your return value.
#include <string>

std::string four_digits(std::string numb)
{
    int numb_digits = numb.size();
    std::string out_string;
    for (int i = 0; i < 4 - numb_digits; i++)
    {
        out_string.push_back('0');
    }
    out_string += numb;
    return out_string;
}
std::string communicationModule(std::string packet)
{
    std::string header, instruction, data1, data2, footer, return_string;
    std::string return_instruction = "FFFF";
    for (int i = 0; i < 20; i++)
    {
        if (i < 4)
        {
            header.push_back(packet[i]);
        }
        else if (i < 8)
        {
            instruction.push_back(packet[i]);
        }
        else if (i < 12)
        {
            data1.push_back(packet[i]);
        }
        else if (i < 16)
        {
            data2.push_back(packet[i]);
        }
        else if (i < 20)
        {
            footer.push_back(packet[i]);
        }
    }
    if (instruction == "0F12")
    { 
        int sum = stoi(data1) + stoi(data2);
        if (sum > 9999) sum = 9999;
        std::string ssum = four_digits(std::to_string(sum));

        return_string = header + return_instruction + ssum + "0000" + footer;
    }
    if (instruction == "B7A2")
    {
        int difference = stoi(data1) - stoi(data2);
        if (difference < 0) difference = 0;
        std::string sdifference = four_digits(std::to_string(difference));
        return_string = header + return_instruction + sdifference + "0000" + footer;
    }
    if (instruction == "C3D9")
    {
        int product = stoi(data1) * stoi(data2);
        if (product > 9999) product = 9999;
        std::string sproduct = four_digits(std::to_string(product));
        return_string = header + return_instruction + sproduct + "0000" + footer;
    }
    return return_string;
}
