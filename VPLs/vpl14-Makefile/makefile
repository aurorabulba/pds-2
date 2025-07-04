# Define o compilador C++
CXX = g++

# Define as flags de compilação
# -Wall: Habilita todos os warnings
# -std=c++17: Especifica o padrão C++17
# -Iinclude: Adiciona o diretório 'include' ao caminho de busca de cabeçalhos
CFLAGS = -Wall -std=c++17 -Iinclude

# Define os diretórios de origem, objetos e executáveis
SRCDIR = src
OBJDIR = obj
INCLUDEDIR = include
BINDIR = .

# Define o nome do executável
TARGET = $(BINDIR)/main

# Lista de arquivos fonte C++ (com seus caminhos relativos ao SRCDIR)
# Seus arquivos são Banco.cpp, ContaBancaria.cpp, main.cpp
SRCS = $(SRCDIR)/main.cpp \
		$(SRCDIR)/Banco.cpp \
		$(SRCDIR)/ContaBancaria.cpp 

# Lista de arquivos objeto (gerados a partir dos SRCS, mas com caminho para OBJDIR)
# Usamos 'addprefix' para adicionar 'obj/' antes de cada nome de arquivo .o
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# O alvo padrão
all: $(TARGET)

# Regra para construir o executável final
# Depende de todos os arquivos objeto
$(TARGET): $(OBJS)
	@mkdir -p $(@D) # Cria o diretório do alvo se não existir (para BINDIR)
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) $(OBJS) -o $@
	@echo "Programa '$(TARGET)' compilado com sucesso!"

# Regra genérica para compilar qualquer arquivo .cpp em .o
# A mágica aqui é que o compilador precisa do caminho completo para o .cpp,
# mas o .o será gerado no OBJDIR.
# $^: Todos os pré-requisitos (neste caso, o .cpp e os .hpp incluídos)
# $<: A primeira dependência (o .cpp)
# $@: O nome do alvo (.o)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D) # Cria o diretório 'obj' se não existir
	$(CXX) $(CFLAGS) -c $< -o $@

# Alvo 'clean' para remover arquivos gerados
.PHONY: clean
clean:
	rm -rf $(OBJSDIR) $(TARGET)
	@echo "Diretório '$(OBJDIR)' e executável '$(TARGET)' removidos."

# Alvo 'run' para executar o programa
.PHONY: run
run: $(TARGET)
	$(TARGET)