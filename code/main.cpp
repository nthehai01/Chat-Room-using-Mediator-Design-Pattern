#include "chatroom.h"

int main()
{
  ChatRoom chatroom;

  Participant beau("beau");
  Participant quincy("quincy");
  Participant rafael("rafael");
  Participant berkeley("berkeley");
  Participant evaristo("evaristo");

  beau.join(&chatroom);
  quincy.join(&chatroom);
  rafael.join(&chatroom);
  berkeley.join(&chatroom);

  quincy.send("How's it going?");
  cout << "--------------" << endl;
  berkeley.send("I'm good", &berkeley);

  return 0;
}