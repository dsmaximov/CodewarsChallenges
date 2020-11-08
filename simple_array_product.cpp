/*In this Kata, you will be given a multi-dimensional array containing 2 or more sub-arrays of integers. Your task is to find the maximum product that can be formed by taking any one element 
from each sub-array.

Examples:
solve( [[1, 2],[3, 4]] ) = 8. The max product is given by 2 * 4
solve( [[10,-15],[-1,-3]] ) = 45, given by (-15) * (-3)
solve( [[1,-1],[2,3],[10,-100]] ) = 300, given by (-1) * 3 * (-100)
*/

#include <vector>

int SAP(std::vector<std::vector<int>> v)
{
    int Product = 0;
    int MaxProduct = 0;
    int mainLoop = 0;
    int mainIndex = 0;
    int secArr = 0;
	int secIndex = 0;
    std::vector<int> posVector;

    for (int i = 0; i<v.size(); i++)
    {
        posVector.push_back(0);
    }

	while (mainLoop < v.size())
	{
            while (mainIndex < v[mainLoop].size())
            {
                secArr = 0;
                Product = v[mainLoop][mainIndex];
                while (secArr < v.size())
                {
                    if (secArr!=mainLoop)
                    {
                            Product *= v[secArr][posVector[secArr]];
                            posVector[secArr]++;
                    }
                    secArr++;
                }
                if (secArr == v.size())
                {
                    if (Product > MaxProduct)
                    {
                        MaxProduct = Product;
                    }
                }
                mainIndex++;
            }
        mainLoop++;
	}
    return MaxProduct;
}