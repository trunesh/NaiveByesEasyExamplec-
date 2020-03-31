#include <iostream>
#include <fstream>
#include <vector>
#include<stdio.h>
#include <iterator>
#include<set>
#include <boost/algorithm/string.hpp>
 using namespace std;
/*
 * A class to read data from a csv file.
 */
class CSVReader
{
	string fileName;
	string delimeter;
 
public:
	CSVReader(string filename, string delm = ",") :
			fileName(filename), delimeter(delm)
	{ }
 
	// Function to fetch data from a CSV File
	vector<vector<string> > getData();
};
 
/*
* Parses through csv file line by line and returns the data
* in vector of vector of strings.
*/
vector<vector<string> > CSVReader::getData()
{
	ifstream file(fileName);
 
	vector<vector<string> > dataList;
 
	string line = "";
	// Iterate through each line and split the content using delimeter
	while (getline(file, line))
	{
		vector<string> vec;
		boost::algorithm::split(vec, line, boost::is_any_of(delimeter));
		dataList.push_back(vec);
	}
	// Close the File
	file.close();
 
	return dataList;
}
int main()
{
	// Creating an object of CSVWriter
	CSVReader reader("mycsvfile.csv");
 
	// Get the data from CSV File
	vector<vector<string> > dataList = reader.getData();
 
	// Print the content of row by row on screen
	// for(vector<string> vec : dataList)
	// {
	// 	for(string data : vec)
	// 	{
	// 		cout<<data << " ";
	// 	}
	// 	cout<<endl;
	// }

	double playYesCount=0;
	double playNoCount=0;
	double length=dataList.size()-1;
	cout<<length<<endl;
	 for (int i = 1;i < dataList.size(); i++) {
            //PLAY COLUMN
            if(dataList[i][4]=="yes"){
            	playYesCount++;
            }
            if(dataList[i][4]=="no"){
            	playNoCount++;
            }  
    }  	
 	cout<<"Play Yes count:"<<playYesCount<<" ";
 	cout<<"Play No count:"<<playNoCount;    

 	printf("\n");
 	double ProbabilityYes=playYesCount/length;
 	double ProbabilityNo=playNoCount/length;

 	cout<<"ProbabilityYes:"<<ProbabilityYes<<" ";
 	cout<<"ProbabilityNo :"<<ProbabilityNo;



 	printf("\n OUTLOOK SUNNY OVERCAST and RAINY\n");

 	double sunnyYesCount=0;
 	double sunnyNoCount=0;

 	for (int i = 1;i < dataList.size(); i++) {
            //Outlook--Sunny
            if(dataList[i][0]=="sunny" && dataList[i][4]=="yes"){
            	sunnyYesCount++;
            }
            if(dataList[i][0]=="sunny" && dataList[i][4]=="no"){
            	sunnyNoCount++;
            }  
    }  
    cout<<"sunnyYesCount:"<<sunnyYesCount<<" "<<"sunnyNoCount:"<<sunnyNoCount;
    double TotalSunny=sunnyYesCount+sunnyNoCount;
    double ProbabilitySunnyYes=sunnyYesCount/playYesCount;
    double ProbabilitySunnyNo=sunnyNoCount/playNoCount;

    printf("\n");
    cout<<"ProbabilitySunnyYes:"<<ProbabilitySunnyYes<<" "<<"ProbabilitySunnyNo:"<<ProbabilitySunnyNo;

    printf("\n");

    double overcastYesCount=0;
 	double overcastNoCount=0;

 	for (int i = 1;i < dataList.size(); i++) {
            //Outlook--overcast
            if(dataList[i][0]=="overcast" && dataList[i][4]=="yes"){
            	overcastYesCount++;
            }
            if(dataList[i][0]=="overcast" && dataList[i][4]=="no"){
            	overcastNoCount++;
            }  
    }  
    cout<<"overcastYesCount:"<<overcastYesCount<<" "<<"overcastNoCount:"<<overcastNoCount;
    double Totalovercast=overcastYesCount+overcastNoCount;
    double ProbabilityovercastYes=overcastYesCount/playYesCount;
    double ProbabilityovercastNo=overcastNoCount/playNoCount;

    printf("\n");
    cout<<"ProbabilityovercastYes:"<<ProbabilityovercastYes<<" "<<"ProbabilityovercastNo:"<<ProbabilityovercastNo;

    printf("\n");


    double rainyYesCount=0;
 	double rainyNoCount=0;

 	for (int i = 1;i < dataList.size(); i++) {
            //Outlook--rainy
            if(dataList[i][0]=="rainy" && dataList[i][4]=="yes"){
            	rainyYesCount++;
            }
            if(dataList[i][0]=="rainy" && dataList[i][4]=="no"){
            	rainyNoCount++;
            }  
    }  
    cout<<"rainyYesCount:"<<rainyYesCount<<" "<<"rainyNoCount:"<<rainyNoCount;
    double Totalrainy=rainyYesCount+rainyNoCount;
    double ProbabilityrainyYes=rainyYesCount/playYesCount;
    double ProbabilityrainyNo=rainyNoCount/playNoCount;

    printf("\n");
    cout<<"ProbabilityrainyYes:"<<ProbabilityrainyYes<<" "<<"ProbabilityrainyNo:"<<ProbabilityrainyNo;

    printf("\n");

printf("\n temperature--Sunny temperature--mild temperature-hot \n");

    double coolYesCount=0;
    double coolNoCount=0;

    for (int i = 1;i < dataList.size(); i++) {
            //temperature--Sunny
            if(dataList[i][1]=="cool" && dataList[i][4]=="yes"){
                coolYesCount++;
            }
            if(dataList[i][1]=="cool" && dataList[i][4]=="no"){
                coolNoCount++;
            }  
    }  
    cout<<"coolYesCount:"<<coolYesCount<<" "<<"coolNoCount:"<<coolNoCount;
    double Totalcool=coolYesCount+coolNoCount;
    double ProbabilitycoolYes=coolYesCount/playYesCount;
    double ProbabilitycoolNo=coolNoCount/playNoCount;

    printf("\n");
    cout<<"ProbabilitycoolYes:"<<ProbabilitycoolYes<<" "<<"ProbabilitycoolNo:"<<ProbabilitycoolNo;

    printf("\n");

    double mildYesCount=0;
    double mildNoCount=0;

    for (int i = 1;i < dataList.size(); i++) {
            //temperature--mild
            if(dataList[i][1]=="mild" && dataList[i][4]=="yes"){
                mildYesCount++;
            }
            if(dataList[i][1]=="mild" && dataList[i][4]=="no"){
                mildNoCount++;
            }  
    }  
    cout<<"mildYesCount:"<<mildYesCount<<" "<<"mildNoCount:"<<mildNoCount;
    double Totalmild=mildYesCount+mildNoCount;
    double ProbabilitmildYes=mildYesCount/playYesCount;
    double ProbabilitmildNo=mildNoCount/playNoCount;

    printf("\n");
    cout<<"ProbabilitmildYes:"<<ProbabilitmildYes<<" "<<"ProbabilitmildNo:"<<ProbabilitmildNo;

    printf("\n");

    double hotYesCount=0;
    double hotNoCount=0;

    for (int i = 1;i < dataList.size(); i++) {
            //temperature-hot
            if(dataList[i][1]=="hot" && dataList[i][4]=="yes"){
                hotYesCount++;
            }
            if(dataList[i][1]=="hot" && dataList[i][4]=="no"){
                hotNoCount++;
            }  
    }  
    cout<<"hotYesCount:"<<hotYesCount<<" "<<"hotNoCount:"<<hotNoCount;
    double Totalhot=hotYesCount+hotNoCount;
    double ProbabilityhotYes=hotYesCount/playYesCount;
    double ProbabilityhotNo=hotNoCount/playNoCount;

    printf("\n");
    cout<<"ProbabilityhotYes:"<<ProbabilityhotYes<<" "<<"ProbabilityhotNo:"<<ProbabilityhotNo;

    printf("\n");

    printf("\n HUMIDITY HIGH and NORMAL\n");
    double humidityYesCount=0;
    double humidityNoCount=0;

    for (int i = 1;i < dataList.size(); i++) {
            //temperature--mild
            if(dataList[i][2]=="high" && dataList[i][4]=="yes"){
                humidityYesCount++;
            }
            if(dataList[i][2]=="high" && dataList[i][4]=="no"){
                humidityNoCount++;
            }  
    }  
    cout<<"humidityYesCount:"<<humidityYesCount<<" "<<"humidityNoCount:"<<humidityNoCount;
    double Totalhumidity=humidityYesCount+humidityNoCount;
    double probabilityhighYes=humidityYesCount/playYesCount;
    double probabilityhighNo=humidityNoCount/playNoCount;

    printf("\n");
    cout<<"probabilityhighYes:"<<probabilityhighYes<<" "<<"probabilityhighNo:"<<probabilityhighNo;

    printf("\n");

    double normalYesCount=0;
    double normalNoCount=0;

    for (int i = 1;i < dataList.size(); i++) {
            //humid-normal
            if(dataList[i][2]=="normal" && dataList[i][4]=="yes"){
                normalYesCount++;
            }
            if(dataList[i][2]=="normal" && dataList[i][4]=="no"){
                normalNoCount++;
            }  
    }  
    cout<<"normalYesCount:"<<normalYesCount<<" "<<"normalNoCount:"<<normalNoCount;
    double Totalnormal=normalYesCount+normalNoCount;
    double ProbabilitynormalYes=normalYesCount/playYesCount;
    double ProbabilitynormalNo=normalNoCount/playNoCount;

    printf("\n");
    cout<<"ProbabilitynormalYes:"<<ProbabilitynormalYes<<" "<<"ProbabilitynormalNo:"<<ProbabilitynormalNo;

    printf("\n");

    printf("\n Wind TRUE and FALSE\n");
    double trueYesCount=0;
    double trueNoCount=0;

    for (int i = 1;i < dataList.size(); i++) {
            //temperature--mild
            if(dataList[i][3]=="TRUE" && dataList[i][4]=="yes"){
                trueYesCount++;
            }
            if(dataList[i][3]=="TRUE" && dataList[i][4]=="no"){
                trueNoCount++;
            }  
    }  
    cout<<"trueYesCount:"<<trueYesCount<<" "<<"trueNoCount:"<<trueNoCount;
    double Totaltrue=trueNoCount+trueYesCount;
    double probabilitytrueyes=trueYesCount/playYesCount;
    double probabilitytrueno=trueNoCount/playNoCount;

    printf("\n");
    cout<<"probabilitytrueyes:"<<probabilitytrueyes<<" "<<"probabilitytrueno:"<<probabilitytrueno;

    printf("\n");

    double falseYesCount=0;
    double falseNoCount=0;

    for (int i = 1;i < dataList.size(); i++) {
            //humid-FALSE
            if(dataList[i][3]=="FALSE" && dataList[i][4]=="yes"){
                falseYesCount++;
            }
            if(dataList[i][3]=="FALSE" && dataList[i][4]=="no"){
                falseNoCount++;
            }  
    }  
    cout<<"falseYesCount:"<<falseYesCount<<" "<<"falseNoCount:"<<falseNoCount;
    double Totalfalse=falseYesCount+falseNoCount;
    double probabilityfalseyes=falseYesCount/playYesCount;
    double probabilityfalseno=falseNoCount/playNoCount;

    printf("\n");
    cout<<"probabilityfalseyes:"<<probabilityfalseyes<<" "<<"probabilityfalseno:"<<probabilityfalseno;

    printf("\n");


    printf("Suppose: outlook=sunny,temperature=cool,humidity=high,wind=True,play=yes");

    double Yescanweplay=ProbabilitySunnyYes*ProbabilitycoolYes*probabilityhighYes*probabilitytrueyes*ProbabilityYes;
    cout<<"\nYescanweplay:"<<Yescanweplay;
    printf("\nSuppose: outlook=sunny,temperature=cool,humidity=high,wind=True,play=no");
    
    double wecannotplay=ProbabilitySunnyNo*ProbabilitycoolNo*probabilityhighNo*probabilitytrueno*ProbabilityNo;
    cout<<"\nwecannotplay:"<<wecannotplay;
    
    printf("\n");
    double TotalProbablityColumnValue=(TotalSunny/length)*(Totalcool/length)*(Totalhumidity/length)*(Totaltrue/length);
	cout<<TotalProbablityColumnValue<<"\n";


	printf("\n");

	cout<<"Can we play? YES:"<<Yescanweplay/TotalProbablityColumnValue<<" "<<"Can we play? No:"<<wecannotplay/TotalProbablityColumnValue;
	printf("\n");
	return 0;
 
}