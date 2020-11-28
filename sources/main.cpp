#include <iostream>
#include <cstdlib>

void random_filling(int *array, int size)
{
    int module;
    std::cout << "Choose the module:";
    std::cin >> module;
    if (!array)
        return;
    for (int i = 0; i < size; ++i) 
    {
        array[i] = rand() % module;
    }
}

void hand_filling(int *array, int size)
{
    int size_tmp = size;
    if (!arr)
        return;
    while (size)
    {
        std::cin >> arr[size_tmp - size];
        size--;
    }
}

int *sort_2_stadia(int *array, int *sub1, int *sub2, int size1, int size2)
{
    int *tmp_array = new int[size1 + size2];
    for (int i = 0; i < size1; ++i)
        tmp_array[i] = sub1[i];
    for (int i = size1; i < size1 + size2; ++i)
        tmp_array[i] = sub2[(size2 - 1) - (i - size1)];
    int i = 0, j = size1 + size2 - 1, k = 0;
    
    while (true)
    {
        if (tmp_array[j] >= tmp_array[i])
        {
            array[k] = tmp_array[i];
            i++;
            k++;
            if (k >= (size1 + size2))
            {
                break;
            }
        } else {
            array[k] = tmp_array[j];
            j--;
            k++;
            if (k >= (size1 + size2))
            {
                break;
            }
        }
    }
    return array;
}

int *sort(int *array, int size){
    if (size == 1){
        return array;
    } else if (size == 2){
        if (array[1] < array[0]) {
            int tmp = array[0];
            array[0] = array[1];
            array[1] = tmp;
        }
        return array;
    }
    int *sub1 = new int[size / 2];
    for (int i = 0; i < (size / 2); ++i)
        sub1[i] = array[i];
    int *sub2 = new int[(size / 2) + (size % 2)];
    for (int i = (size / 2); i < size; ++i)
        sub2[i - (size/2)] = array[i];

    sub1 = sort(sub1, size / 2);
    sub2 = sort(sub2, (size / 2) + (size % 2));
    array = sort_2_stadia(array, sub1, sub2, size / 2, (size / 2) + (size % 2));
    return array;
}


int main() {

    std::cout << "Input size of array:";
    int size = 0;
    std::cin >> size;
    int *array = new int[size];

    std::cout << "Choose the method of filling:" << std::endl;
    std::cout << "1.Random filling" << std::endl;
    std::cout << "2.Hand filling" << std::endl;

    int choice = 0;
    std::cin >> choice;

    if (choice == 3)
    {
        delete[](array);
    }
    else if (choice == 1)
    {
        random_filling(array, size);
    } else if (choice == 2)
    {
        hand_filling(array, size);
    }

    int action;
    while (true) 
    {
        std::cout << "Choose action:" << std::endl;
        std::cout << "1.Sort array" << std::endl;
        std::cout << "2.Print array" << std::endl;
        std::cout << "3.Exit" << std::endl;
        std::cin >> action;

        switch (action)
        {
            case 1:
                array = sort(array, size);
                break;
            case 2:
                for (int i = 0; i < size; ++i)
                    std::cout << array[i] << ",";
                break;
            case 3:
                break;
        }
    }


    delete[](array);
    return 0;
}
