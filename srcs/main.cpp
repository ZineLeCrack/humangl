#include "Includes.hpp"

static Human	human;
static float	rotX = 0.0f;
static float	rotY = 0.0f;
static int		lastMouseX = 0;
static int		lastMouseY = 0;
static bool		isDragging = false;

void	display() {
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, -8.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);

	human.draw_legs();
	human.draw_body();
	human.draw_arms();
	human.draw_head();

	glEnd();
}

void	keypress(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}

void	imgui_set_window() {
	ImVec2 size(400, 300);
	SetNextWindowSize(size, ImGuiCond_FirstUseEver);
	Begin("Settings");
	SeparatorText(" Rotation ");
	Text("Rotation: x = %d, y = %d", (int)rotX, (int)rotY);
	if (Button("Reset  rotation")) rotX = rotY = 0.0f;
	End();
}

int main() {
	if (!glfwInit()) {
		cerr << RED "Error: init error" << RESET << endl;
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	GLFWwindow* window = glfwCreateWindow(2560, 1600, "HumanGL", NULL, NULL);
	if (!window) {
		glfwTerminate();
		cerr << RED "Error: init error" << RESET << endl;
		return 1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	glfwSetCursorPosCallback(window, [](GLFWwindow* w, double xpos, double ypos) {
		(void)w;
		if(isDragging){
			int dx = int(xpos) - lastMouseX;
			int dy = int(ypos) - lastMouseY;

			rotY += dx * 0.5f;
			rotX += dy * 0.5f;

			lastMouseX = int(xpos);
			lastMouseY = int(ypos);
		}
	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* w, int button, int action, int mods) {
		(void)w;
		(void)mods;
		if(button == GLFW_MOUSE_BUTTON_LEFT){
			if(action == GLFW_PRESS){
				isDragging = true;
				double xpos, ypos;
				glfwGetCursorPos(w, &xpos, &ypos);
				lastMouseX = int(xpos);
				lastMouseY = int(ypos);
			} else {
				isDragging = false;
			}
		}
	});

	IMGUI_CHECKVERSION();
	CreateContext();
	ImGuiIO &io = GetIO();
	io.Fonts->AddFontFromFileTTF("fonts/Minecraftia.ttf", 24.0f);
	StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 460");

	glEnable(GL_DEPTH_TEST);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, width / (float)height, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);


	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		NewFrame();

		keypress(window);

		display();

		imgui_set_window();

		Render();
		ImGui_ImplOpenGL3_RenderDrawData(GetDrawData());

		glfwSwapBuffers(window);
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
