NAME = humangl

CC = c++
CFLAGS = -Wall -Wextra -Werror -g3 -std=c++11 -Iincludes
GLFLAGS = -lGL -lGLU -lGLEW -lglfw

IMGUI_SRCDIR = includes/imgui
SRCDIR = srcs
OBJDIR = objs

IMGUI_SRCS =	imgui.cpp \
				imgui_draw.cpp \
				imgui_impl_glfw.cpp \
				imgui_impl_opengl3.cpp \
				imgui_tables.cpp \
				imgui_widgets.cpp

IMGUI_SRCS := $(addprefix $(IMGUI_SRCDIR)/, $(IMGUI_SRCS))

IMGUI_OBJS = $(IMGUI_SRCS:$(IMGUI_SRCDIR)/%.cpp=$(OBJDIR)/%.o)

SRCS = Matrix.cpp Shaders.cpp Vec3.cpp ModelStack.cpp Hand.cpp image.cpp Human.cpp utils.cpp main.cpp 

SRCS := $(addprefix $(SRCDIR)/, $(SRCS))

OBJS += $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OBJS += $(IMGUI_SRCS:$(IMGUI_SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(IMGUI_SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(GLFLAGS)
	@echo "\033[32m✔ Compilation completed\033[0m"

clean:
	$(RM) imgui.ini
	$(RM) -r $(OBJDIR)
	@echo "\033[33m✔ $(OBJDIR) suppressed\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[31m✔ $(NAME) suppressed\033[0m"

re: fclean all
