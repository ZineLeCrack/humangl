#include "Includes.hpp"

Human	human;

static int	lastMouseX = 0;
static int	lastMouseY = 0;
static bool	isDragging = false;

static bool	showDebug1 = false;
static bool	showDebug2 = false;
static bool	showDebug3 = false;
static bool	showDebug4 = false;

static bool key1Released = true;
static bool key2Released = true;
static bool key3Released = true;
static bool key4Released = true;

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

static float toRadians = M_PIf / 180.0f;

void framebuffer_size_callback(GLFWwindow *window, int width, int heigth)
{
	(void)window;
	glViewport(0, 0, width, heigth);
}

void	draw_cube(Shaders &shader, const Matrix &model)
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
	GLint viewLoc = glGetUniformLocation(shader.shaderProgram, "uView");
	GLint colorLoc = glGetUniformLocation(shader.shaderProgram, "uColor");

	Matrix view = Matrix::lookAt({0.0f, 0.0f, 21.0f - human.get_zoom()}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f});
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.data());
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data());
	glUniform3f(colorLoc, 1.0f, 0.0f, 0.0f);

	glBindVertexArray(cubeVAO);
	glDrawArrays(GL_LINES, 0, 24);
	glBindVertexArray(0);
}

void	display(Shaders &modelShader, Shaders &cubeShader)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Matrix view = Matrix::lookAt({0.0f, 0.0f, 21.0f - human.get_zoom()}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f});

	glUseProgram(modelShader.shaderProgram);
	GLint viewLoc = glGetUniformLocation(modelShader.shaderProgram, "uView");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.data());

	glUseProgram(cubeShader.shaderProgram);
	GLint viewLoc2 = glGetUniformLocation(cubeShader.shaderProgram, "uView");
	glUniformMatrix4fv(viewLoc2, 1, GL_FALSE, view.data());

	glUseProgram(modelShader.shaderProgram);

	Matrix Rx = Matrix::rotateX(human.get_rotX() * toRadians);
	Matrix Ry = Matrix::rotateY(human.get_rotY() * toRadians);

	Matrix model = Ry * Rx;

	modelStack.loadIdentity();
	modelStack.push();
	modelStack.current() = model;

	human.draw(modelStack, modelShader, cubeShader, cube);
}

void	keypress(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		human.get_animation() = JUMP;
		human.get_animation_frame() = glfwGetTime();
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		human.get_animation() = FLY;
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
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		human.get_animation() = DISCO_DANCE;
		human.get_animation_frame() = glfwGetTime();
	}

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		if (key1Released) { showDebug1 = !showDebug1; key1Released = false; }
	}
	else key1Released = true;

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		if (key2Released) { showDebug2 = !showDebug2; key2Released = false; }
	}
	else key2Released = true;

	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		if (key3Released) { showDebug3 = !showDebug3; key3Released = false; }
	}
	else key3Released = true;

	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
		if (key4Released) { showDebug4 = !showDebug4; key4Released = false; }
	}
	else key4Released = true;
}

void	imgui_set_window()
{
	ImVec2 pos1(20, 20);
	SetNextWindowPos(pos1, ImGuiCond_FirstUseEver);

	if (showDebug1) {
		Begin("Settings", NULL, ImGuiWindowFlags_AlwaysAutoResize);
		SeparatorText(" Info ");
		Text("fps: %d", (int)GetIO().Framerate);
		Checkbox("Display cube", &cube);

		SeparatorText(" Skin ");
		Checkbox("Use skin", &human.get_use_texture());
		SameLine();
		if (RadioButton("Classic", human.get_slim() == 0)) human.change_slim();
		SameLine();
		if (RadioButton("Slim", human.get_slim() == 1)) human.change_slim();

		SeparatorText(" Rotation ");
		Text("Rotation: x = %d, y = %d", (int)human.get_rotX(), (int)human.get_rotY());
		if (Button("Reset  rotation")) human.get_rotX() = human.get_rotY() = 0.0f;

		SeparatorText(" Size ");
		if (Button("Reset Size")) human.reset_size();
		SliderFloat("Zoom", &human.get_zoom(), 0.0f, 20.0f);
		SliderFloat("Global size", &human.get_size(), 0.5f, 2.0f);
		SliderFloat("Body size", &human.get_body_size(), 0.5f, 2.0f);
		SliderFloat("Head size", &human.get_head_size(), 0.5f, 2.0f);
		SliderFloat("Left upper arm size", &human.get_left_upper_arm_size(), 0.5f, 2.0f);
		SliderFloat("Right upper arm size", &human.get_right_upper_arm_size(), 0.5f, 2.0f);
		SliderFloat("Left forearm size", &human.get_left_forearm_size(), 0.5f, 2.0f);
		SliderFloat("Right forearm size", &human.get_right_forearm_size(), 0.5f, 2.0f);
		SliderFloat("Left thigh size", &human.get_left_thigh_size(), 0.5f, 2.0f);
		SliderFloat("Right thigh size", &human.get_right_thigh_size(), 0.5f, 2.0f);
		SliderFloat("Left lower leg size", &human.get_left_lower_leg_size(), 0.5f, 2.0f);
		SliderFloat("Right lower leg size", &human.get_right_lower_leg_size(), 0.5f, 2.0f);

		SeparatorText(" Animations ");
		if (Button("Reset")) { human.get_animation() = STAY; human.get_animation_frame() = 0; } SameLine();
		if (Button("Walk")) { human.get_animation() = WALK; human.get_animation_frame() = glfwGetTime(); } SameLine();
		if (Button("Sprint")) { human.get_animation() = SPRINT; human.get_animation_frame() = glfwGetTime(); } SameLine();
		if (Button("Jump")) { human.get_animation() = JUMP; human.get_animation_frame() = glfwGetTime(); } SameLine();
		if (Button("Disco Dance")) {human.get_animation() = DISCO_DANCE; human.get_animation_frame() = glfwGetTime(); } SameLine();
		if (Button("Fly")) {human.get_animation() = FLY; human.get_animation_frame() = glfwGetTime(); }
		End();
	}

	ImVec2 pos2(1420, 20);
	SetNextWindowPos(pos2, ImGuiCond_FirstUseEver);

	if (showDebug2) {
		Begin(" Colors ", NULL, ImGuiWindowFlags_AlwaysAutoResize);

		SeparatorText(" Change Colors ");
		ColorEdit3(" Skin ", human.get_skin_color());
		ColorEdit3(" Body ", human.get_body_color());
		ColorEdit3(" Legs ", human.get_legs_color());
		ColorEdit3(" Foots ", human.get_foots_color());

		SeparatorText(" Show / Hide Body Parts ");
		Checkbox("Head", &human._showHead);
		Checkbox("Body", &human._showBody);
		Checkbox("Right Upper Arm", &human._showRightUpperArm);
		Checkbox("Left Upper Arm", &human._showLeftUpperArm);
		Checkbox("Right Forearm Arm", &human._showRightForearm);
		Checkbox("Left Forearm Arm", &human._showLeftForearm);
		Checkbox("Right thigh", &human._showRightthigh);
		Checkbox("Left thigh", &human._showLeftthigh);
		Checkbox("Right Lower Leg", &human._showRightLowerLeg);
		Checkbox("Left Lower Leg", &human._showLeftLowerLeg);
		Checkbox("Hands", &human._showHands);
		Checkbox("Wings", &human._showWings);
		End();
	}

	ImVec2 pos3(7,449);
	SetNextWindowPos(pos3, ImGuiCond_FirstUseEver);
	if (showDebug3) {
		Begin(" Fingers Angles ", NULL, ImGuiWindowFlags_AlwaysAutoResize);
		SeparatorText(" Right Hand ");
		SliderFloat2("R_Thumb Finger", human._rightHand->thumbFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("R_T_Reset")) human._rightHand->reset(0);
		SliderFloat3("R_Index Finger", human._rightHand->indexFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("R_I_Reset")) human._rightHand->reset(1);
		SliderFloat3("R_Middle Finger", human._rightHand->middleFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("R_M_Reset")) human._rightHand->reset(2);
		SliderFloat3("R_Ring Finger", human._rightHand->ringFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("R_R_Reset")) human._rightHand->reset(3);
		SliderFloat3("R_Little Finger", human._rightHand->littleFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("R_L_Reset")) human._rightHand->reset(4);

		if (Button("R_Reset All")) human._rightHand->reset(-1);

		SeparatorText(" Left Hand ");
		SliderFloat2("L_Thumb Finger", human._leftHand->thumbFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("L_T_Reset")) human._leftHand->reset(0);
		SliderFloat3("L_Index Finger", human._leftHand->indexFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("L_I_Reset")) human._leftHand->reset(1);
		SliderFloat3("L_Middle Finger", human._leftHand->middleFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("L_M_Reset")) human._leftHand->reset(2);
		SliderFloat3("L_Ring Finger", human._leftHand->ringFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("L_R_Reset")) human._leftHand->reset(3);
		SliderFloat3("L_Little Finger", human._leftHand->littleFingerPhalangeAngle, -90.0f, 90.0f); SameLine();
		if (Button("L_L_Reset")) human._leftHand->reset(4);

		if (Button("L_Reset All")) human._leftHand->reset(-1);
		End();
	}
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
	glfwSwapInterval(0);

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		throw runtime_error ("failed to initialize Glew\n");
	}

	Shaders modelShader;
	Shaders cubeShader;
	try {
		modelShader = Shaders("shaders/model.vert", "shaders/model.frag");
		cubeShader = Shaders("shaders/color.vert", "shaders/color.frag");
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

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

	glUseProgram(modelShader.shaderProgram);
	Matrix	proj = Matrix::perspective(45, width / (float)height, 0.1f, 100.0f);
	GLint	projLoc = glGetUniformLocation(modelShader.shaderProgram, "uProjection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, proj.data());

	glUseProgram(cubeShader.shaderProgram);
	Matrix	cubeProj = Matrix::perspective(45, width / (float)height, 0.1f, 100.0f);
	GLint	cubeProjLoc = glGetUniformLocation(cubeShader.shaderProgram, "uProjection");
	glUniformMatrix4fv(cubeProjLoc, 1, GL_FALSE, cubeProj.data());

	if (ac == 2) {
		if (!load_image(av[1]))
			return 1;
	} else {
		if (!load_image("skins/default.png"))
			return 1;
	}
	glUniform1i(glGetUniformLocation(modelShader.shaderProgram, "uUseTexture"), 0);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		NewFrame();

		glUseProgram(modelShader.shaderProgram);
		glUniform1i(glGetUniformLocation(modelShader.shaderProgram, "uUseTexture"), human.get_use_texture());
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, human.get_texture());

		glfwSetScrollCallback(window, scroll_callback);
		keypress(window);

		display(modelShader, cubeShader);

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
