#include "Includes.hpp"

Human	human;

static int	lastMouseX = 0;
static int	lastMouseY = 0;
static bool	isDragging = false;

static bool	cube = false;

static GLuint cubeVAO = 0, cubeVBO = 0;

static const float cubeVertices[] = {
	 0.5f,  0.5f,  0.5f,  -0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,  -0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,   0.5f,  0.5f, -0.5f,
	 0.5f,  0.5f, -0.5f,   0.5f,  0.5f,  0.5f,

	 0.5f, -0.5f,  0.5f,  -0.5f, -0.5f,  0.5f,
	-0.5f, -0.5f,  0.5f,  -0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,   0.5f, -0.5f, -0.5f,
	 0.5f, -0.5f, -0.5f,   0.5f, -0.5f,  0.5f,

	 0.5f,  0.5f,  0.5f,   0.5f, -0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,  -0.5f, -0.5f,  0.5f,
	 0.5f,  0.5f, -0.5f,   0.5f, -0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f,  -0.5f, -0.5f, -0.5f
};

ModelStack modelStack;

static float toRadians = M_PI / 180.0f;

void framebuffer_size_callback(GLFWwindow *window, int width, int heigth)
{
	(void)window;
	glViewport(0, 0, width, heigth);
}

static void	draw_cube(Shaders &shader, const Matrix &model)
{
	glLineWidth(2.0f);
	if (cubeVAO == 0) {
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);

		glBindVertexArray(cubeVAO);
		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	}

	glUseProgram(shader.shaderProgram);
	GLint modelLoc = glGetUniformLocation(shader.shaderProgram, "uModel");
	GLint colorLoc = glGetUniformLocation(shader.shaderProgram, "uColor");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data());
	glUniform3f(colorLoc, 1.0f, 0.0f, 0.0f);

	glBindVertexArray(cubeVAO);
	glDrawArrays(GL_LINES, 0, 24);
	glBindVertexArray(0);
}

void	display(Shaders &shader)
{
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Matrix view = Matrix::lookAt({0.0f, 0.0f, 21.0f - human.get_zoom()}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f});
	GLint viewLoc = glGetUniformLocation(shader.shaderProgram, "uView");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.data());

	Matrix Rx = Matrix::rotateX(human.get_rotX() * toRadians);
	Matrix Ry = Matrix::rotateY(human.get_rotY() * toRadians);

	Matrix model = Ry * Rx;
	GLint modelLoc = glGetUniformLocation(shader.shaderProgram, "uModel");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data());

	modelStack.loadIdentity();
	modelStack.push();
	modelStack.current() = model;
	if (human.get_animation() == JUMP) {
		float angle = -sin((glfwGetTime() - human.get_animation_frame()) * 5.0f);
		modelStack.push();
		if (angle > 0.0f) modelStack.translate(0.0f, angle * 0.5f, 0.0f);
		else modelStack.translate(0.0f, angle * 0.05f, 0.0f);
	}

	human.draw(modelStack, shader);

	if (human.get_animation() == JUMP) modelStack.pop();

	if (cube) draw_cube(shader, model);
}

void	keypress(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		human.get_animation() = JUMP;
		human.get_animation_frame() = glfwGetTime();
	}
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		human.get_animation() = WALK;
		human.get_animation_frame() = glfwGetTime();
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		human.get_animation() = SPRINT;
		human.get_animation_frame() = glfwGetTime();
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		human.get_animation() = STAY;
		human.get_animation_frame() = glfwGetTime();
	}
}

void	imgui_set_window()
{
	ImVec2 pos1(20, 20);
	SetNextWindowPos(pos1, ImGuiCond_FirstUseEver);
	// SetNextWindowCollapsed(true, ImGuiCond_FirstUseEver);
	Begin("Settings", NULL, ImGuiWindowFlags_AlwaysAutoResize);

	SeparatorText(" Info ");
	Text("fps: %d", (int)GetIO().Framerate);

	SeparatorText(" Skin ");
	if (Button("Use skin")) human.change_texture();

	SeparatorText(" Rotation ");
	Text("Rotation: x = %d, y = %d", (int)human.get_rotX(), (int)human.get_rotY());

	if (Button("Reset  rotation")) human.get_rotX() = human.get_rotY() = 0.0f;
	SameLine();
	if (Button("Display  cube")) cube = !cube;

	SeparatorText(" Size ");
	SliderFloat("Zoom", &human.get_zoom(), 0.0f, 20.0f);

	SliderFloat("Size", &human.get_size(), 0.5f, 2.0f);

	SeparatorText(" Animations ");
	if (Button("Reset")) {
		human.get_animation() = STAY;
		human.get_animation_frame() = 0;
	}
	SameLine();
	if (Button("Walk")) {
		human.get_animation() = WALK;
		human.get_animation_frame() = glfwGetTime();
	}
	SameLine();
	if (Button("Sprint")) {
		human.get_animation() = SPRINT;
		human.get_animation_frame() = glfwGetTime();
	}
	SameLine();
	if (Button("Jump")) {
		human.get_animation() = JUMP;
		human.get_animation_frame() = glfwGetTime();
	}

	End();

	ImVec2 pos2(1420, 20);
	// SetNextWindowCollapsed(true, ImGuiCond_FirstUseEver);
	SetNextWindowPos(pos2, ImGuiCond_FirstUseEver);
	Begin(" Colors ", NULL, ImGuiWindowFlags_AlwaysAutoResize);

	ColorEdit3(" Skin ", human.get_skin_color());
	ColorEdit3(" Body ", human.get_body_color());
	ColorEdit3(" Legs ", human.get_legs_color());
	ColorEdit3(" Foots ", human.get_foots_color());

	Checkbox("Head", &human._showHead);
	Checkbox("Body", &human._showBody);
	Checkbox("Right Upper Arm", &human._showRightUpperArm);
	Checkbox("Left Upper Arm", &human._showLeftUpperArm);
	Checkbox("Right Forearm Arm", &human._showRightForearm);
	Checkbox("Left Forearm Arm", &human._showLeftForearm);
	Checkbox("Right Tigh", &human._showRightTigh);
	Checkbox("Left Tigh", &human._showLeftTigh);
	Checkbox("Right Lower Leg", &human._showRightLowerLeg);
	Checkbox("Left Lower Leg", &human._showLeftLowerLeg);
	Checkbox("Right Foot", &human._showRightFoot);
	Checkbox("Left Foot", &human._showLeftFoot);
	End();
}

static void	scroll_callback(GLFWwindow* window, double x, double y)
{
	float	&zoom = human.get_zoom();

	(void)window;
	(void)x;

	if (y > 0 && zoom < 20.0f) human.get_zoom() += (zoom < 19.6f ? 0.4f : 20.0f - zoom);
	if (y < 0 && zoom > 0.0f)  human.get_zoom() -= (zoom > 0.4f ? 0.4f : zoom);
}

int main(int ac, char **av)
{
	if (ac > 2) {
		cerr << RED "Error: usage: ./humangl (skin.png)" RESET << endl;
		return 1;
	}

	if (!glfwInit()) {
		cerr << RED "Error: init error" << RESET << endl;
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1920, 1080, "HumanGL", NULL, NULL);
	if (!window) {
		glfwTerminate();
		cerr << RED "Error: init error" << RESET << endl;
		return 1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		throw runtime_error ("failed to initialize Glew\n");
	}

	Shaders shader("shaders/vertex.vert", "shaders/fragment.frag");

	glfwSetCursorPosCallback(window, [](GLFWwindow* w, double xpos, double ypos) {
		(void)w;
		if (isDragging){
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
		if (button == GLFW_MOUSE_BUTTON_RIGHT){
			if (action == GLFW_PRESS){
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

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glEnable(GL_DEPTH_TEST);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	glUseProgram(shader.shaderProgram);
	Matrix	proj = Matrix::perspective(45, width / (float)height, 0.1f, 100.0f);
	GLint	projLoc = glGetUniformLocation(shader.shaderProgram, "uProjection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, proj.data());

	if (ac == 2) {
		if (!load_image(av[1]))
			return 1;
		human.set_texture(true);
		glUniform1i(glGetUniformLocation(shader.shaderProgram, "uUseTexture"), 0);
	}

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		NewFrame();

		if (ac == 2) {
			glUseProgram(shader.shaderProgram);
			glUniform1i(glGetUniformLocation(shader.shaderProgram, "uUseTexture"), human.get_use_texture());
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, human.get_texture());
		}

		glfwSetScrollCallback(window, scroll_callback);
		keypress(window);

		display(shader);

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
