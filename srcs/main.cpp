#include "Includes.hpp"

static Human	human;

static int	lastMouseX = 0;
static int	lastMouseY = 0;
static bool	isDragging = false;

static bool	cube = false;

static void	draw_cube() {
	glBegin(GL_LINES);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, 0.5, 0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, 0.5, 0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, 0.5, 0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, 0.5, -0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, 0.5, -0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, 0.5, -0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, 0.5, -0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, 0.5, 0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, -0.5, 0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, -0.5, 0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, -0.5, 0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, -0.5, -0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, -0.5, -0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, -0.5, -0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, -0.5, -0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, -0.5, 0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, 0.5, 0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, -0.5, 0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, 0.5, 0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, -0.5, 0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, 0.5, -0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(0.5, -0.5, -0.5);

	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, 0.5, -0.5);
	glColor3d(1.0, 0.0, 0.0); glVertex3d(-0.5, -0.5, -0.5);

	glEnd();
}

void	display() {
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 21.0f - human.get_zoom(), 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glRotatef(human.get_rotX(), 1.0f, 0.0f, 0.0f);
	glRotatef(human.get_rotY(), 0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);

	human.draw_legs();
	human.draw_body();
	human.draw_arms();
	human.draw_head();

	glEnd();

	if (cube) draw_cube();
}

void	keypress(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}

void	imgui_set_window() {
	ImVec2 size1(400, 300);
	ImVec2 pos1(20, 20);
	SetNextWindowSize(size1, ImGuiCond_FirstUseEver);
	SetNextWindowPos(pos1, ImGuiCond_FirstUseEver);
	Begin("Settings");
	SeparatorText(" Rotation ");
	Text("Rotation: x = %d, y = %d", (int)human.get_rotX(), (int)human.get_rotY());
	if (Button("Reset  rotation")) human.get_rotX() = human.get_rotY() = 0.0f;
	SameLine();
	if (Button("Display  cube")) cube = !cube;
	SeparatorText(" Size ");
	SliderFloat("Zoom", &human.get_zoom(), 0.0f, 20.0f);
	End();

	ImVec2 size2(400, 370);
	ImVec2 pos2(20, 340);
	SetNextWindowSize(size2, ImGuiCond_FirstUseEver);
	SetNextWindowPos(pos2, ImGuiCond_FirstUseEver);
	Begin(" Colors ");
	ColorPicker3(" Foots ", human.get_foots_color());
	ColorPicker3(" Legs ", human.get_legs_color());
	ColorPicker3(" Body ", human.get_body_color());
	ColorPicker3(" Arms ", human.get_arms_color());
	ColorPicker3(" Head ", human.get_head_color());
	End();
}

static void	scroll_callback(GLFWwindow* window, double x, double y) {
	float	&zoom = human.get_zoom();

	(void)window;
	(void)x;

	if (y > 0 && zoom < 20.0f) human.get_zoom() += (zoom < 19.6f ? 0.4f : 20.0f - zoom);
	if (y < 0 && zoom > 0.0f)  human.get_zoom() -= (zoom > 0.4f ? 0.4f : zoom);
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

			human.get_rotY() += dx * 0.5f;
			human.get_rotX() += dy * 0.5f;

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

		glfwSetScrollCallback(window, scroll_callback);
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
