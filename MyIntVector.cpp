#include <iostream>
#include <list>
using namespace std;

class MyIntVector {
private:
    int* data;           // 동적 배열을 가리키는 포인터
    size_t capacity;     // 현재 할당된 배열 크기
    size_t length;       // 실제 저장된 요소 개수

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

        /* TODO */
        int* newData = new int[capacity * 2];   

        for (size_t i = 0; i < length; ++i)     
            newData[i] = data[i];

        delete[] data;                          

        data = newData;                         
        capacity *= 2;                          
    }

public:

    // 초기 capacity를 2로 설정, length는 0으로
    MyIntVector() : capacity(2), length(0) {
        /* TODO */
        data = new int[capacity];   // 초기 동적 할당
    }

    ~MyIntVector() {
        /* TODO */
        delete[] data;
    }

    void push_back(const int& value) {
        /* TODO */
        if (length == capacity)
            resize();               // capacity 초과 시 확장

        data[length++] = value;     // 값 추가 후 length 증가
    }

    int pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length];
    }

    int& operator[](const int index){
        return data[index];
    }

    size_t size() const {
        return length;
    }
};

void testVector(const string& name, std::list<int> values) {
    cout << "------------------" << endl;
    MyIntVector vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";

    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector("IntVec", {1, 2, 3, 4, 5, 6});
    return 0;
}
