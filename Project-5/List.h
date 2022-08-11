#ifndef H_LIST
#define H_LIST
#define SIZE 10

using namespace std;

template <class T>
class List {
protected:
    T* list;
    int length;
    int maxSize;
public:
    List(int size = SIZE);
    List(const List<T>& list);
    bool isEmpty() const;
    bool isFull() const;
    T max() const;
    T min() const;
    int listSize() const;
    int maxListSize() const;
    void print() const;
    bool isItemAtEqual(int location, const T& item) const;
    void insertAt(int location, const T& insertItem);
    void insertEnd(const T& insertItem);
    void removeAt(int location);
    void retrieveAt(int location, T& retItem) const;
    void replaceAt(int location, const T& repItem);
    void clearList();
    int seqSearch(const T& item) const;
    void insert(const T& insertItem);
    void remove(const T& removeItem);
    void removeAll(const T& removeItem);
    const List<T>& operator=(const List<T>& otherList);
    ~List();
};

#endif
