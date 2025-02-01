#include <iostream> // Girdi ve çıktı işlemleri için gerekli
#include <string>   // String işlemleri için gerekli
#define nullptr NULL // Eski C++ sürümleri ile uyumluluk için nullptr tanımlaması
using namespace std;

// Tek bir görevi temsil eden sınıf
class Task {
public:
    int id;               // Görevin benzersiz kimliği
    string description;   // Görevin açıklaması
    bool completed;       // Görevin tamamlanma durumu
    Task* next;           // Bağlı listedeki bir sonraki göreve işaretçi

    // Task nesnesini başlatmak için yapıcı fonksiyon
    Task(int taskId, const string& taskDescription)
        : id(taskId), description(taskDescription), completed(false), next(nullptr) {
    }
};

// To-do listi bağlı liste şeklinde yöneten sınıf
class ToDoList {
private:
    Task* head;    // Listenin başına işaretçi
    int taskCount; // Toplam görev sayısı
public:
    // Boş bir to-do list başlatmak için yapıcı
    ToDoList() : head(nullptr), taskCount(0) {}

    // Belleği serbest bırakmak için destructor (tüm görevleri siler)
    ~ToDoList() {
        Task* current = head; // Listenin başından başla
        while (current) {     // Listenin tamamını dolaş
            Task* temp = current;   // Şu anki görevi geçici sakla
            current = current->next; // Bir sonraki göreve geç
            delete temp;            // Şu anki görevi sil
        }
    }

    // Yeni görev ekleme fonksiyonu
    void addTask(const string& description) {
        Task* newTask = new Task(++taskCount, description); // Benzersiz ID ile yeni görev oluştur
        if (!head) {
            head = newTask; // Liste boşsa, yeni görevi başa ekle
        }
        else {
            Task* temp = head; // Listenin başından başla
            while (temp->next) { // Listenin sonuna kadar git
                temp = temp->next;
            }
            temp->next = newTask; // Yeni görevi sona ekle
        }
        cout << "Task added successfully with ID: " << newTask->id << endl;
    }

    // ID’ye göre görev silme fonksiyonu
    void removeTask(int id) {
        if (!head) { // Liste boşsa
            cout << "To-Do list is empty.\n";
            return;
        }
        // Silinecek görev listenin başındaysa
        if (head->id == id) {
            Task* temp = head;
            head = head->next;
            delete temp;
            cout << "Task with ID " << id << " removed successfully.\n";
            return;
        }
        // Silinecek görevi bulmak için listeyi dolaş
        Task* current = head;
        while (current->next && current->next->id != id) {
            current = current->next;
        }
        if (current->next) { // Görev bulunduysa
            Task* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "Task with ID " << id << " removed successfully.\n";
        }
        else {
            cout << "Task with ID " << id << " not found.\n";
        }
    }

    // ID’ye göre görevi tamamlanmış olarak işaretleme fonksiyonu
    void markCompleted(int id) {
        Task* current = head;
        while (current) {
            if (current->id == id) {
                current->completed = true;
                cout << "Task with ID " << id << " marked as completed.\n";
                return;
            }
            current = current->next;
        }
        cout << "Task with ID " << id << " not found.\n";
    }

    // Listedeki tüm görevleri gösterme fonksiyonu
    void displayTasks() const {
        if (!head) {
            cout << "To-Do list is empty.\n";
            return;
        }
        Task* current = head;
        while (current) {
            cout << "ID: " << current->id
                << " | Description: " << current->description
                << " | Status: " << (current->completed ? "Completed" : "Not Completed")
                << endl;
            current = current->next;
        }
    }
};

// To-do list uygulamasını çalıştıran ana fonksiyon
int main() {
    ToDoList toDoList;   // ToDoList nesnesi oluştur
    int choice, id;      // Menü seçimi ve görev ID'si için değişkenler
    string description;  // Görev açıklaması için değişken

    do {
        // Menü görüntüle
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Task\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Display All Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Kullanıcı seçimini al

        switch (choice) {
        case 1:
            cout << "Enter task description: ";
            cin.ignore(); // Geriye kalan newline karakterini yoksay
            getline(cin, description); // Tam açıklamayı al
            toDoList.addTask(description); // Görevi ekle
            break;
        case 2:
            cout << "Enter task ID to remove: ";
            cin >> id;
            toDoList.removeTask(id); // Görevi sil
            break;
        case 3:
            cout << "Enter task ID to mark as completed: ";
            cin >> id;
            toDoList.markCompleted(id); // Görevi tamamlanmış olarak işaretle
            break;
        case 4:
            toDoList.displayTasks(); // Tüm görevleri göster
            break;
        case 5:
            cout << "Exiting...\n"; // Çıkış işlemi
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // Geçersiz giriş
        }
    } while (choice != 5); // Kullanıcı çıkış yapana kadar döngüyü devam ettir

    return 0;
}
