# Derleyici
CXX = g++

# Derleme bayrakları
CXXFLAGS = -std=c++11 -Iheaders

# Hedef yürütülebilir dosya
TARGET = main

# Kaynak dosyalar
SRCS = src/main.cpp src/part1.cpp src/part2.cpp src/part3.cpp

# Nesne dosyaları (kaynak dosyalar ile aynı isimde ama .o uzantılı)
OBJS = $(SRCS:.cpp=.o)

# Girdi dosyaları
INPUT_FILES = inputs/part1_input.txt inputs/part2_input.txt inputs/part3_input.txt # Girdi dosyalarını buraya ekleyin

# Hedef dosya için kurallar
$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

# .cpp dosyalarını .o'ya çevirme kuralı
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Temizlik işlemi
clean:
	rm -f $(OBJS) $(TARGET)
