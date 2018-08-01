#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include <fstream>

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

pair<double,double> centroid(vector<pair<double,double>> v)
{
    double totX;
    double totY;

    for (int i = 0; i < v.size(); ++i)
    {
        totX+=v[i].first;
        totY+=v[i].second;
    }

    double avgX = totX/v.size();
    double avgY = totY/v.size();


    pair<double,double> centroid = make_pair(avgX,avgY);
    return centroid;
}

int index(pair<double, double> p, vector<pair<double,double>> data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        if(p == data[i])
        {
            return i+1;
        }
    }
}

int main()
{
    //cout << "Hello, World!" << endl;

    vector<pair<double,double>> data;
    data.push_back(make_pair(2,10)); // 0+1 = 1
    data.push_back(make_pair(2,5));  // 1+1 = 2
    data.push_back(make_pair(8,4));  // 2+1 = 3
    data.push_back(make_pair(5,8));  // 3+1 = 4
    data.push_back(make_pair(7,5));  // 4+1 = 5
    data.push_back(make_pair(6,4));  // 5+1 = 6
    data.push_back(make_pair(1,2));  // 6+1 = 7
    data.push_back(make_pair(4,9));  // 7+1 = 8

    //initial seeds (centroids of each cluster)  : 1, 4, 7 -> (2,10), (5,8), (1,2)
    vector<pair<double,double>> cluster1;
    vector<pair<double,double>> cluster2;
    vector<pair<double,double>> cluster3;

    vector<pair<double,double>> centroids;
    centroids.push_back(data[0]);
    centroids.push_back(data[3]);
    centroids.push_back(data[6]);

    for (int k = 0; k < 5; ++k)
    {
        for (int i = 0; i < data.size() ; ++i)
        {

            if(distance(centroids[0].first,centroids[0].second,data[i].first,data[i].second) <
               distance(centroids[1].first,centroids[1].second,data[i].first,data[i].second) &&
               distance(centroids[0].first,centroids[0].second,data[i].first,data[i].second) <
               distance(centroids[2].first,centroids[2].second,data[i].first,data[i].second))
            {
                cluster1.push_back(data[i]);
            }
            else if(distance(centroids[1].first,centroids[1].second,data[i].first,data[i].second) <
                    distance(centroids[0].first,centroids[0].second,data[i].first,data[i].second) &&
                    distance(centroids[1].first,centroids[1].second,data[i].first,data[i].second) <
                    distance(centroids[2].first,centroids[2].second,data[i].first,data[i].second))
            {
                cluster2.push_back(data[i]);
            }
            else if(distance(centroids[2].first,centroids[2].second,data[i].first,data[i].second) <
                    distance(centroids[0].first,centroids[0].second,data[i].first,data[i].second) &&
                    distance(centroids[2].first,centroids[2].second,data[i].first,data[i].second) <
                    distance(centroids[1].first,centroids[1].second,data[i].first,data[i].second))
            {
                cluster3.push_back(data[i]);
            }
        }


        ofstream out ("Results", ios_base::app);

        out << "Iteration " << k << endl;
        out << "Cluster1" <<  endl;
        for (int j = 0; j < cluster1.size(); ++j)
        {
            out << index(cluster1[j],data) << " ";

        }

        out << "" << endl;
        out << "(" << centroid(cluster1).first << ", " << centroid(cluster1).second << ")" << endl;


        out << "Cluster2" <<  endl;
        for (int j = 0; j < cluster2.size(); ++j)
        {
            out << index(cluster2[j],data) << " ";
        }

        out << "" << endl;
        out << "(" << centroid(cluster2).first << ", " << centroid(cluster2).second << ")" << endl;

        out << "Cluster3" <<  endl;
        for (int j = 0; j < cluster3.size(); ++j)
        {
            out << index(cluster3[j],data) << " ";

        }

        out << "" << endl;
        out << "(" << centroid(cluster3).first << ", " << centroid(cluster3).second << ")" << endl;
        out << "" << endl;
        

        //new centroids
        centroids.clear();
        centroids.push_back(centroid(cluster1));
        centroids.push_back(centroid(cluster2));
        centroids.push_back(centroid(cluster3));

        //clear cluster vectors
        cluster1.clear();
        cluster2.clear();
        cluster3.clear();

    }






//    for (int k = 0; k < 6; ++k)
//    {
//        for (int i = 0; i < data.size() ; ++i)
//        {
//            if(distance(data[0].first,data[0].second,data[i].first,data[i].second) <
//               distance(data[3].first,data[3].second,data[i].first,data[i].second) &&
//               distance(data[0].first,data[0].second,data[i].first,data[i].second) <
//               distance(data[6].first,data[6].second,data[i].first,data[i].second))
//            {
//                cluster1.push_back(data[i]);
//            }
//            else if(distance(data[3].first,data[3].second,data[i].first,data[i].second) <
//                    distance(data[0].first,data[0].second,data[i].first,data[i].second) &&
//                    distance(data[3].first,data[3].second,data[i].first,data[i].second) <
//                    distance(data[6].first,data[6].second,data[i].first,data[i].second))
//            {
//                cluster2.push_back(data[i]);
//            }
//            else if(distance(data[6].first,data[6].second,data[i].first,data[i].second) <
//                    distance(data[0].first,data[0].second,data[i].first,data[i].second) &&
//                    distance(data[6].first,data[6].second,data[i].first,data[i].second) <
//                    distance(data[3].first,data[3].second,data[i].first,data[i].second))
//            {
//                cluster3.push_back(data[i]);
//            }
//        }
//    }





    

    return 0;
}