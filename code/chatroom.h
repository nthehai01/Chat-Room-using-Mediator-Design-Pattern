#include <iostream>
#include <string>

using namespace std;

class ChatRoom;

class Participant
{
private:
  string name;
  ChatRoom *room;

public:
  Participant();
  Participant(string);
  bool join(ChatRoom *);
  void receive(string, Participant *);
  void send(string, Participant * = nullptr);
  bool operator==(Participant &);
  bool operator!=(Participant &);
  ~Participant();
};

class ChatRoom
{
private:
  Participant *participants;
  int numParticipants;

public:
  ChatRoom();
  void registration(Participant &);
  void send(string, Participant *, Participant *);
  ~ChatRoom();
};