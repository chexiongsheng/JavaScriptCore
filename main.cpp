#include <iostream>
#include <JavaScriptCore/JavaScript.h>

int main() {
  JSStringRef string = JSStringCreateWithUTF8CString("Hello JSCore!");
  int length = JSStringGetLength(string);
  std::cout << "Length of the String: " << length << std::endl;
  char buffer[20];
  JSStringGetUTF8CString(string, buffer, JSStringGetLength(string) + 1);
  std::cout << "String: " << buffer << std::endl;
  JSStringRelease(string);
  return 0;
}
