#include <iostream>
#include <string>
using namespace std;

class Image {
  public:
    virtual void display() = 0;
};

class RealImage : public Image {
  private:
    string filename;

  public:
    RealImage(const string &filename) : filename(filename) {
      // Simulate loading the image (this can be a resource-intensive operation)
      cout << "Loading image: " << filename << endl;
    }

    void display() override {
      cout << "Displaying image: " << filename << endl;
    }
};

class ImageProxy : public Image {
  private:
    RealImage *realImage; // Reference to the Real Object
    string filename;

  public:
    ImageProxy(const string &filename) : filename(filename), realImage(nullptr) {}

    void display() override {
      // The Proxy checks if the Real Object is created and loads it if necessary
      if (realImage == nullptr) {
        realImage = new RealImage(filename);
      }

      realImage->display();
    }
};

int main() {
  // Create a proxy to an image
  Image *image = new ImageProxy("example.jpg");

  // Display the image (the Proxy will load the Real Object if necessary)
  image->display();

  // Displaying the image again (the Proxy won't reload it)
  image->display();

  delete image; // Clean up

  return 0;
}