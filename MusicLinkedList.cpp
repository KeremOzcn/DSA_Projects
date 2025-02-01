#include <iostream>
#include <string>
using namespace std;
// Class to represent a song in the playlist
class Song {
public:
	string title; // Title of the song
	string artist; // Artist of the song
	Song* next; // Pointer to the next song
	Song* prev; // Pointer to the previous song
	// Constructor to initialize a song with title and artist
	Song(string t, string a) : title(t), artist(a), next(NULL), prev(NULL) {}
};
// Class to manage the playlist
class Playlist {
private:
	Song* head; // Pointer to the first song in the playlist
	Song* tail; // Pointer to the last song in the playlist
	Song* current; // Pointer to the currently playing song
	int size; // Total number of songs in the playlist
public:
	// Constructor to initialize an empty playlistPlaylist() : head(NULL), tail(NULL), current(NULL), size(0) {}
	// Add a song to the end of the playlist
	void addSong(string title, string artist) {
		Song* newSong = new Song(title, artist); // Create a new song
		if (!head) {
			// If the playlist is empty, set head and tail to the new song
			head = tail = newSong;
		}
		else {
			// Otherwise, add the song to the end of the playlist
			tail->next = newSong;
			newSong->prev = tail;
			tail = newSong;
		}
		size++; // Increment the size of the playlist
		cout << "Song added to the playlist!\n";
	}
	// Insert a song at a specific position in the playlist
	void insertSong(string title, string artist, int position) {
		if (position < 1 || position > size + 1) {
			// Position is invalid if it's less than 1 or greater than size + 1
			cout << "Invalid position!\n";
			return;
		}
		Song* newSong = new Song(title, artist); // Create a new song
		if (position == 1) {// Insert at the beginning
			newSong->next = head;
			if (head) head->prev = newSong;
			head = newSong;
			if (!tail) tail = head; // If the list was empty, update the tail
		}
		else {
			// Insert at a specific position
			Song* temp = head;
			for (int i = 1; i < position - 1; i++) {
				temp = temp->next;
			}
			newSong->next = temp->next;
			newSong->prev = temp;
			if (temp->next) temp->next->prev = newSong;
			temp->next = newSong;
			if (!newSong->next) tail = newSong; // Update the tail if added at the end
		}
		size++; // Increment the size of the playlist
		cout << "Song inserted at position " << position << "!\n";
	}
	// Remove the first song from the playlist
	void removeFirstSong() {
		if (!head) {
			// If the playlist is empty, nothing to remove
			cout << "Playlist is empty!\n";
			return;
		}Song* temp = head;
		head = head->next; // Move the head to the next song
		if (head) head->prev = NULL; // Update the previous pointer of the new head
		else tail = NULL; // If the list is now empty, set the tail to NULL
		delete temp; // Free the memory of the removed song
		size--; // Decrement the size of the playlist
		cout << "First song removed!\n";
	}
	// Remove the last song from the playlist
	void removeLastSong() {
		if (!tail) {
			// If the playlist is empty, nothing to remove
			cout << "Playlist is empty!\n";
			return;
		}
		Song* temp = tail;
		tail = tail->prev; // Move the tail to the previous song
		if (tail) tail->next = NULL; // Update the next pointer of the new tail
		else head = NULL; // If the list is now empty, set the head to NULL
		delete temp; // Free the memory of the removed song
		size--; // Decrement the size of the playlist
		cout << "Last song removed!\n";
	}
	// Remove a song from a specific position
	void removeSongAtPosition(int position) {
		if (position < 1 || position > size) {// Position is invalid if it's less than 1 or greater than size
			cout << "Invalid position!\n";
			return;
		}
		if (position == 1) {
			// Remove the first song
			removeFirstSong();
		}
		else if (position == size) {
			// Remove the last song
			removeLastSong();
		}
		else {
			// Remove a song at a specific position
			Song* temp = head;
			for (int i = 1; i < position; i++) {
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp; // Free the memory of the removed song
			size--; // Decrement the size of the playlist
			cout << "Song removed from position " << position << "!\n";
		}
	}
	// Play the next song
	void playNext() {
		if (!current) current = head; // Start from the first song if no song is playingelse current = current->next; // Move to the next song
		if (current) {
			cout << "Now playing: " << current->title << " - " << current->artist << "\n";
		}
		else {
			cout << "End of playlist!\n";
		}
	}
	// Play the previous song
	void playPrevious() {
		if (!current) current = tail; // Start from the last song if no song is playing
		else current = current->prev; // Move to the previous song
		if (current) {
			cout << "Now playing: " << current->title << " - " << current->artist << "\n";
		}
		else {
			cout << "Start of playlist!\n";
		}
	}
	// Display the currently playing song
	void displayCurrentSong() {
		if (current) {
			cout << "Current song: " << current->title << " - " << current->artist << "\n";
		}
		else {
			cout << "No song is currently playing.\n";
		}
	}
	// Display all songs in the playlist
	void displayPlaylist() {
		if (!head) {
			cout << "Playlist is empty!\n";
			return;
		}
		Song* temp = head;
		cout << "Playlist:\n";
		while (temp) {
			cout << temp->title << " - " << temp->artist << "\n";
			temp = temp->next;
		}
	}
	// Display all songs in reverse order
	void displayPlaylistReverse() {
		if (!tail) {
			cout << "Playlist is empty!\n";
			return;
		}
		Song* temp = tail;
		cout << "Playlist (reverse order):\n";
		while (temp) {
			cout << temp->title << " - " << temp->artist << "\n";
			temp = temp->prev;
		}
	}
	// Search for a song by its title
	int searchSong(string title) {
		Song* temp = head;
		int position = 1;
		while (temp) {
			if (temp->title == title) {
				cout << "Song found at position " << position << "!\n";
				return position;
			}
			temp = temp->next;
			position++;
		}
		cout << "Song not found!\n";
		return -1;
	}
	// Get the total number of songs in the playlist
	int countSongs() {
		return size;
	}
};
// Main function to test the playlist management system
int main() {
	Playlist playlist;
	int choice, position;string title, artist;
	while (true) {
		cout << "\nWelcome to the Music Playlist Management System!\n";
		cout << "1. Add a song to the end\n";
		cout << "2. Insert a song at a specific position\n";
		cout << "3. Remove the first song\n";
		cout << "4. Remove the last song\n";
		cout << "5. Remove a song from a specific position\n";
		cout << "6. Play the next song\n";
		cout << "7. Play the previous song\n";
		cout << "8. Display the current song\n";
		cout << "9. Display the playlist\n";
		cout << "10. Display the playlist in reverse order\n";
		cout << "11. Search for a song\n";
		cout << "12. Count the total number of songs\n";
		cout << "13. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter the song title: ";
			cin.ignore();
			getline(cin, title);
			cout << "Enter the artist: ";
			getline(cin, artist);
			playlist.addSong(title, artist);break;
		case 2:
			cout << "Enter the song title: ";
			cin.ignore();
			getline(cin, title);
			cout << "Enter the artist: ";
			getline(cin, artist);
			cout << "Enter the position: ";
			cin >> position;
			playlist.insertSong(title, artist, position);
			break;
		case 3:
			playlist.removeFirstSong();
			break;
		case 4:
			playlist.removeLastSong();
			break;
		case 5:
			cout << "Enter the position: ";
			cin >> position;
			playlist.removeSongAtPosition(position);
			break;
		case 6:
			playlist.playNext();
			break;
		case 7:
			playlist.playPrevious();
		break;case 8:
			playlist.displayCurrentSong();
			break;
		case 9:
			playlist.displayPlaylist();
			break;
		case 10:
			playlist.displayPlaylistReverse();
			break;
		case 11:
			cout << "Enter the song title: ";
			cin.ignore();
			getline(cin, title);
			playlist.searchSong(title);
			break;
		case 12:
			cout << "Total songs in the playlist: " << playlist.countSongs() << "\n";
			break;
		case 13:
			cout << "Exiting...\n";
			return 0;
		default:
			cout << "Invalid choice! Please try again.\n";
		}
	}
}