#include"Game.h"
#include"PackGroup.h"
void Game::updateKeyboardInput()
{
	//Program
	if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(this->window, GLFW_TRUE);
	}
	//Camera
	if (this->rigidBodies4D[0]->isGravity)
	{
		if (this->inputs[8]->getKeyDoublePress(this->window, this->iMoveForward, 0.25f, this->dt))
		{
			this->camera.isRuning = true;
		}
	}
	if (glfwGetKey(this->window, this->iMoveForward) == GLFW_PRESS)
	{
		this->camera.move(this->dt,FORWARD,this->rigidBodies4D[0]);
	}
	if (this->inputs[8]->getKeyOnRelease(this->window, this->iMoveForward))
	{
		this->camera.isRuning = false;
	}
	if (glfwGetKey(this->window, this->iMoveBackward) == GLFW_PRESS)
	{
		this->camera.move(this->dt, BACKWARD, this->rigidBodies4D[0]);
	}
	if (glfwGetKey(this->window, this->iMoveLeft) == GLFW_PRESS)
	{
		this->camera.move(this->dt, LEFT, this->rigidBodies4D[0]);
	}
	if (glfwGetKey(this->window, this->iMoveRight) == GLFW_PRESS)
	{
		this->camera.move(this->dt, RIGHT, this->rigidBodies4D[0]);
	}
	if (glfwGetKey(this->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		this->camera.jump(this->dt,DOWN, this->isGround, this->rigidBodies4D[0]);
	}
	if (glfwGetKey(this->window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		this->camera.jump(this->dt, UP, this->isGround, this->rigidBodies4D[0]);
	}
	if (this->inputs[0]->getKeyDoublePress(this->window, GLFW_KEY_SPACE, 0.25f, this->dt))
	{
		this->rigidBodies4D[0]->isGravity = !this->rigidBodies4D[0]->isGravity;
	}
	if (glfwGetKey(this->window, this->iMoveAna) == GLFW_PRESS)
	{
		this->camera.move(this->dt, ANA, this->rigidBodies4D[0]);
	}
	if (glfwGetKey(this->window, this->iMoveKata) == GLFW_PRESS)
	{
		this->camera.move(this->dt, KATA, this->rigidBodies4D[0]);
	}
	this->camera.update_camera(this->dt, this->rigidBodies4D[0]);
	//Set and remove lights

	if (this->inputs[1]->getKeyOnPress(this->window, this->iSwitchInventory))
	{
		this->curserMode = !this->curserMode;
		if (this->curserMode) {
			glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
		if (!this->curserMode) {
			glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			this->firstMouse = !this->firstMouse;
		}
	}
	if (this->inputs[4]->getKeyOnPress(this->window, this->iTurnDirection))
	{
		int dir;
		if (cameraDir == "W")
		{
			this->camera.fit_direction(dir = 0);
		}
		if (cameraDir == "X")
		{
			this->camera.fit_direction(dir = 1);
		}
		if (cameraDir == "Y")
		{
			this->camera.fit_direction(dir = 2);
		}
		if (cameraDir == "Z")
		{
			this->camera.fit_direction(dir = 3);
		}
		if (dir == 0)
		{
			cameraDir = "X";
		}
		if (dir == 1)
		{
			cameraDir = "Y";
		}
		if (dir == 2)
		{
			cameraDir = "Z";
		}
		if (dir == 3)
		{
			cameraDir = "W";
		}
	}
	if (this->inputs[5]->getKeyOnPress(this->window, this->iSwitchFrame))
	{
		if (ObjectRendering == "Objects")
		{
			this->frameType = 1;
		}
		if (ObjectRendering == "Objects And Wire Frames")
		{
			this->frameType = 0;
		}
		if (this->frameType == 0)
		{
			ObjectRendering = "Objects";
		}
		if (this->frameType == 1)
		{
			ObjectRendering = "Objects And Wire Frames";
		}
	}
	if (this->inputs[7]->getKeyOnPress(this->window, this->iSwitchCoordinate))
	{
		this->isRenderCoordinate4D = !this->isRenderCoordinate4D;
	}
	if (glfwGetKey(this->window, this->iFovOut) == GLFW_PRESS)
	{
		this->fov *= 1 + 0.01f * 60 * dt;
		this->fov = clamp(this->fov, -180.f, 180.f);
		updateProjectMat();
	}
	if (glfwGetKey(this->window, this->iFovIn) == GLFW_PRESS)
	{
		this->fov /= 1 + 0.01f * 60 * dt;
		this->fov = clamp(this->fov, -180.f, 180.f);
		updateProjectMat();
	}
	if(this->inputs[6]->getKeyOnPress(this->window, GLFW_KEY_1))
	{
		this->mode = SHOOTING;
		this->targetIcon->logo = this->pointerTexs[SHOOTING];
		this->shaders[TERRAIND4]->use();
		this->shaders[TERRAIND4]->set1i(this->mode == PAINTING, "isPainting");
		this->shaders[TERRAIND4]->set1i(this->mode == BUILDING, "isBuilding");
		this->shaders[TERRAIND4]->set1i(this->mode == AREA_DELETING, "isAreaDeleting");
	}
	if (this->inputs[6]->getKeyOnPress(this->window, GLFW_KEY_2))
	{
		this->mode = CONTROLING;
		this->targetIcon->logo = this->pointerTexs[CONTROLING];
		this->shaders[TERRAIND4]->use();
		this->shaders[TERRAIND4]->set1i(this->mode == PAINTING, "isPainting");
		this->shaders[TERRAIND4]->set1i(this->mode == BUILDING, "isBuilding");
		this->shaders[TERRAIND4]->set1i(this->mode == AREA_DELETING, "isAreaDeleting");
	}
	if (this->inputs[6]->getKeyOnPress(this->window, GLFW_KEY_3))
	{
		this->mode = PAINTING;
		this->targetIcon->logo = this->pointerTexs[PAINTING];
		this->shaders[TERRAIND4]->use();
		this->shaders[TERRAIND4]->set1i(this->mode == PAINTING, "isPainting");
		this->shaders[TERRAIND4]->set1i(this->mode == BUILDING, "isBuilding");
		this->shaders[TERRAIND4]->set1i(this->mode == AREA_DELETING, "isAreaDeleting");
	}
	if (this->inputs[6]->getKeyOnPress(this->window, GLFW_KEY_4))
	{
		this->mode = BUILDING;
		this->targetIcon->logo = this->pointerTexs[BUILDING];
		this->shaders[TERRAIND4]->use();
		this->shaders[TERRAIND4]->set1i(this->mode == PAINTING, "isPainting");
		this->shaders[TERRAIND4]->set1i(this->mode == BUILDING, "isBuilding");
		this->shaders[TERRAIND4]->set1i(this->mode == AREA_DELETING, "isAreaDeleting");
	}
	if (this->inputs[6]->getKeyOnPress(this->window, GLFW_KEY_5))
	{
		this->mode = DELETING;
		this->targetIcon->logo = this->pointerTexs[DELETING];
		this->shaders[TERRAIND4]->use();
		this->shaders[TERRAIND4]->set1i(this->mode == PAINTING, "isPainting");
		this->shaders[TERRAIND4]->set1i(this->mode == BUILDING, "isBuilding");
		this->shaders[TERRAIND4]->set1i(this->mode == AREA_DELETING, "isAreaDeleting");
	}
	if (this->inputs[6]->getKeyOnPress(this->window, GLFW_KEY_6))
	{
		this->mode = AREA_DELETING;
		this->targetIcon->logo = this->pointerTexs[AREA_DELETING];
			this->deleteMap3D->unselectArea();
			this->shaders[TERRAIND4]->use();
			this->shaders[TERRAIND4]->set1i(this->mode == PAINTING, "isPainting");
			this->shaders[TERRAIND4]->set1i(this->mode == BUILDING, "isBuilding");
			this->shaders[TERRAIND4]->set1i(this->mode == AREA_DELETING, "isAreaDeleting");
	}

	if (this->mode == SHOOTING)
	{
		
		if (this->inputs[2]->getMouseOnPress(this->window, GLFW_MOUSE_BUTTON_2))
		{
			this->hitIndex = ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups,this->walls4D,this->dynamites4D, true,true,true,this->camera.position4D, this->camera.forward4D, this->camera.right4D,&this->hitPosNear);
		}
		
		if (this->hitIndex != -1)
		{
			if (this->isFixedTime)
			{
				if (this->hitIndex < this->rigidBodies4D.size())
				{
					if (this->rigidBodies4D[this->hitIndex]->objectName == "Glass4D")
					{
						erase_animation4D(&this->shifts4D, &this->floats4D, &this->rotates4D, this->hitIndex);
						shift_animation4D(this->shifts4D, this->floats4D, this->rotates4D, this->hitIndex, -1);
						erase_joint4d(&this->sticks4D, &this->springs4D, &this->hingeConstraints, this->hitIndex);
						shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->hitIndex, -1);
						this->rigidBodies4D.erase(this->rigidBodies4D.begin() + this->hitIndex);
						this->sounds[8]->play(length(this->camera.position4D-this->rigidBodies4D[this->hitIndex]->position4D),this->soundVolume);
					}
					else {
						glm::vec4 force4D = 750.f * normalize(this->camera.forward4D);
						this->rigidBodies4D[this->hitIndex]->forceSystems4D.push_back(new ForceSystem4D(force4D, world_pos_to_body(this->rigidBodies4D[this->hitIndex], this->hitPosNear)));
						this->rigidBodies4D[0]->forceSystems4D.push_back(new ForceSystem4D(-force4D, glm::vec4(0.f)));
					}
					this->sounds[4]->play(length(this->camera.position4D - this->hitPosNear), this->soundVolume);
				}
				else if (this->hitIndex >= this->rigidBodies4D.size() && this->hitIndex < size_of_objects4d(this->rigidBodies4D,this->dynamites4D2))
				{
					this->dynamites4D2[this->hitIndex - this->rigidBodies4D.size()]->objectName = "Exploding Dynamite";
					this->sounds[4]->play(length(this->camera.position4D - this->hitPosNear), this->soundVolume);
				}
				else if (this->hitIndex >= size_of_objects4d(this->rigidBodies4D, this->dynamites4D2) && this->hitIndex < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2,this->groups, this->walls4D))
				{
					if (find_wall4d(this->groups, this->walls4D, this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2))->objectName == "Glass4D")
					{
						erase_joint4d(&this->sticks4D, &this->springs4D, &this->hingeConstraints, this->hitIndex);
						shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->hitIndex, -1);
						erase_wall4d(this->groups, this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2));
						this->sounds[8]->play(length(this->camera.position4D - find_wall4d(this->groups, this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2))->position4D), this->soundVolume);
					}
					this->sounds[5]->play(length(this->camera.position4D - this->hitPosNear), this->soundVolume);
				}
				else if (this->hitIndex >= size_of_objects4d(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D)&& this->hitIndex < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2,this->groups,this->walls4D,this->dynamites4D))
				{
					this->dynamites4D[this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2,this->groups, this->walls4D)]->objectName="Exploding Dynamite";
					this->sounds[4]->play(length(this->camera.position4D - this->hitPosNear), this->soundVolume);
				}
				else {
					this->sounds[5]->play(length(this->camera.position4D - this->hitPosNear), this->soundVolume);
				}
				this->emitters4D.push_back(new Emitter4D(1, this->hitPosNear,glm::vec4(0.f),2.f));
			this->hitIndex = -1;
			}
		}
	}

	if (this->mode == CONTROLING)
	{
		//std::cout << "this->hitIndex : " << this->hitIndex << "\n";
		if (this->controlType == 0 || this->controlType == 1)
		{
			if (this->inputs[2]->getMouseOnPress(this->window, GLFW_MOUSE_BUTTON_2))
			{
				this->hitIndex = ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D, this->dynamites4D, false,true,false,this->camera.position4D, this->camera.forward4D, this->camera.right4D, &this->hitPosNear);
				if (this->hitIndex != -1);
				{
					if (this->hitIndex < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2))
					{
						if (this->controlType == 0)
						{
						    if (length(this->hitPosNear - this->camera.frontPosition4D) < 2.f)
						    {
								find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->isFrozen = false;
								this->hitPosToBody = world_pos_to_body(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex), this->hitPosNear);
								this->dragLines4D.clear();
								this->dragLines4D.push_back(new JointLine4D());
							}
							else
							{
								this->dragLines4D.clear();
								this->hitIndex = -1;
							}
						}
						if (this->controlType == 1)
						{
						    if (length(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->position4D - this->camera.frontPosition4D) < 2.f)
						    {
								find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->isFrozen = true;
							}
							else
							{
								this->dragLines4D.clear();
								this->hitIndex = -1;
							}
						}
					}
				}
			}
		}

		if (this->controlType == 0 || this->controlType == 1)
		{
			if (this->hitIndex != -1) {
				if (this->hitIndex < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2))
				{
					if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS && glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_1) == GLFW_RELEASE)
					{
						if (this->isFixedTime)
						{
							if (this->controlType == 0)
							{
							    if (length(body_pos_to_world(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex), this->hitPosToBody) - this->camera.frontPosition4D) < 2.f)
							    {
									this->dragLines4D[0]->update_joint_line4D(body_pos_to_world(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex), this->hitPosToBody), this->camera.frontPosition4D);
									glm::vec4 force4D = 15.f * (this->camera.frontPosition4D - find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->position4D);
									find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->forceSystems4D.push_back(new ForceSystem4D(force4D, this->hitPosToBody));
									find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->velocity4D *= pow(0.25f, this->dt);
									find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->angularVelocity4D =
										find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->angularVelocity4D * pow(0.86f, this->dt);
									this->rigidBodies4D[0]->forceSystems4D.push_back(new ForceSystem4D(-force4D, glm::vec4(0.f)));
								}
								else
								{
									this->dragLines4D.clear();
									this->hitIndex = -1;
								}
							}
							if (this->controlType == 1)
							{
							    if (length(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->position4D - this->camera.frontPosition4D) < 2.f)
							    {
									find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->set_position4D(this->camera.frontPosition4D);
								}
								else
								{
									this->dragLines4D.clear();
									this->hitIndex = -1;
								}
							}
						}
					}
					if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS && glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
					{
						if (this->isFixedTime)
						{
							if (this->controlType == 0)
							{
							    if (length(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->position4D - this->camera.frontPosition4D) < 2.f)
							    {
									this->dragLines4D.clear();
									float objectMass = find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->mass;
									float handMass = 0.1f;
									glm::vec4 force4D = 15.f * (objectMass / (objectMass + handMass)) * this->camera.forward4D;
									find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, this->hitIndex)->forceSystems4D.push_back(new ForceSystem4D(force4D, glm::vec4(0.f)));
									this->rigidBodies4D[0]->forceSystems4D.push_back(new ForceSystem4D(-force4D, glm::vec4(0.f)));
								}
								else
								{
									this->dragLines4D.clear();
									this->hitIndex = -1;
								}
							}
						}
					}
				}
			}
		}

		if (this->controlType == 2)
		{
			if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS && glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_1) == GLFW_RELEASE)
			{
				this->dragLines4D.clear();
				int index=0;
				for (int i = 1; i < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2); i++)
				{
					if (length(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->position4D - this->camera.frontPosition4D) < 5.f)
					{
						find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->isFrozen = false;
						this->dragLines4D.push_back(new JointLine4D());
						this->dragLines4D[index]->update_joint_line4D(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->position4D, this->camera.frontPosition4D);
						index++;
						glm::vec4 force4D = 7.5f * (this->camera.frontPosition4D - find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->position4D);
						find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->forceSystems4D.push_back(new ForceSystem4D(force4D, glm::vec4(0.f)));
						find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->velocity4D *= pow(0.25f, this->dt);
						this->rigidBodies4D[0]->forceSystems4D.push_back(new ForceSystem4D(-force4D, glm::vec4(0.f)));
					}
				}
			}
			if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS && glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
			{
				this->dragLines4D.clear();
				for (int i = 1; i < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2); i++)
				{
					if (length(find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->position4D - this->camera.frontPosition4D) < 5.f)
					{
						float objectMass = find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->mass;
						float handMass = 0.1f;
						glm::vec4 force4D = 7.5f * (objectMass / (objectMass + handMass)) * this->camera.forward4D;
						find_rigidbody4d(this->rigidBodies4D, this->dynamites4D2, i)->forceSystems4D.push_back(new ForceSystem4D(force4D, glm::vec4(0.f)));
						this->rigidBodies4D[0]->forceSystems4D.push_back(new ForceSystem4D(-force4D, glm::vec4(0.f)));
					}
				}
			}
		}

		if (this->controlType == 0 || this->controlType == 1)
		{
			if (this->inputs[2]->getMouseOnRelease(this->window, GLFW_MOUSE_BUTTON_2))
			{
				this->hitIndex = -1;
				if (this->controlType == 0)
				{
					this->dragLines4D.clear();
				}
			}
		}

		if (this->controlType == 2)
		{
			if (this->inputs[2]->getMouseOnRelease(this->window, GLFW_MOUSE_BUTTON_2))
			{
				this->dragLines4D.clear();
			}
		}
	}
	if (this->mode == PAINTING) {
		ray::get_ray_detect_terrain_pos4D(this->camera.position4D, this->camera.forward4D, this->camera.right4D,this->groups,&this->hittingPos4D);
		this->shaders[TERRAIND4]->use();
		this->shaders[TERRAIND4]->setVec4f(this->hittingPos4D, "hittingPos4D");
		this->shaders[TERRAIND4]->set1f(this->paintScale, "paintScale");
		if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
		{
			if (this->isHardPainting)
				this->paintType = this->paintType0 + 10;
			else
				this->paintType = this->paintType0;
			this->textures3D[BLEND]->paintColors(this->paintType, 
				glm::vec3(this->hittingPos4D.x, this->hittingPos4D.z, this->hittingPos4D.w), 
				this->paintScale, this->isSphericalPainting);
		}
	}
	if (this->mode == BUILDING) {

		if (glfwGetKey(this->window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS|| glfwGetKey(this->window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
		{
			this->hittingPos4D = get_build_position4D(this->camera.position4D, this->camera.forward4D, this->hittingPos4D, true);
		}
		else {
			if (this->buildMode != BUILD_STICK && this->buildMode != BUILD_SPRING)
			{
				this->isFindPoint= ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D, this->dynamites4D, true, true,true, this->camera.position4D, this->camera.forward4D, this->camera.right4D, &this->hittingPos4D)!=-1;
				this->hittingPos4D = get_build_position4D(this->camera.position4D, this->camera.forward4D, this->hittingPos4D, false);
			}
		}
		if (this->buildMode != BUILD_STICK && this->buildMode != BUILD_SPRING)
		{
			this->shaders[TERRAIND4]->use();
			this->shaders[TERRAIND4]->setVec4f(this->hittingPos4D, "hittingPos4D");
		}

		if (this->inputs[2]->getMouseOnPress(this->window, GLFW_MOUSE_BUTTON_2))
		{
			if (this->isFindPoint) {
				this->sounds[7]->play(0.f, this->soundVolume);
				//if (this->buildMode == BUILD_WALL)
				//{
				//	shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2) + size_of_walls4d(this->groups), 1);
				//	shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2) + size_of_walls4d(this->groups), 1);
				//	this->walls4D.push_back(new Wall4D("Hypercube", Hypercube(get_wall_build_scale4D()), get_wall_build_position4D(this->hittingPos4D), alg::bivec4(), get_wall_build_scale4D(), 1.6f, 0.25f, true, this->wallTexs3D[this->buildTexture],0.f, this->buildColor, BOX4D, this->shaders[this->buildShader]));
				//	this->groups = pack_group(this->groups, &this->walls4D, &this->terrains4D);
				//}

				if (this->buildMode == BUILD_OBJECT)
				{
					shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2) + size_of_walls4d(this->groups), 1);
					shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2) + size_of_walls4d(this->groups), 1);
					if (this->buildCol == HYPERCUBE)
						this->walls4D.push_back(new Wall4D("Hypercube", Hypercube(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture],0.f, this->buildColor, BOX4D, this->shaders[this->buildShader]));
					if (this->buildCol == HYPERSPHERE)
						this->walls4D.push_back(new Wall4D("Hypersphere", Hypersphere(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f,this->buildColor, SPHERE4D, this->shaders[this->buildShader]));
					if (this->buildCol == HYPERCAPSULE)
						this->walls4D.push_back(new Wall4D("Hypercapsule", Hypercapsule(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, CAPSULE4D, this->shaders[this->buildShader]));
					if (this->buildCol == HYPERCYLINDER)
						this->walls4D.push_back(new Wall4D("Hypercylinder", Hypercylinder(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == HYPERCONE)
						this->walls4D.push_back(new Wall4D("Hypercone", Hypercone(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == HYPERPOT)
						this->walls4D.push_back(new Wall4D("Hyperpot", Hyperpot(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == TRIPRISM)
						this->walls4D.push_back(new Wall4D("TriPrism", TriPrism(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if(this->buildCol == HYPERSLOPE)
						this->walls4D.push_back(new Wall4D("Hyperslope", Hyperslope(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == HYPERQUAD)
						this->walls4D.push_back(new Wall4D("DoubleQuads4d", DoubleQuads4d(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == PENTACHORON)
						this->walls4D.push_back(new Wall4D("Pentachoron", Pentachoron(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == HYPERPYRAMID)
						this->walls4D.push_back(new Wall4D("Pyramid4D", Pyramid4D(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == HEXADECACHORON)
						this->walls4D.push_back(new Wall4D("Hexadecachoron", Hexadecachoron(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					if (this->buildCol == HEXACOSICHORON)
						this->walls4D.push_back(new Wall4D("Hexacosichoron", Hexacosichoron(this->buildScale / 2.f), get_cap_position4D(this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f, 0.f, 0.f)), this->buildRotation, this->buildScale, this->buildParameter.z, this->buildParameter.w, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, this->shaders[this->buildShader]));
					this->groups = pack_group(this->groups, &this->walls4D, &this->terrains4D);
				}
				
				if (this->buildMode == BUILD_RIGIDBODY)
				{
					shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, this->rigidBodies4D.size(), 1);
					shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->rigidBodies4D.size(), 1);
					if (this->buildCol == HYPERCUBE)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hypercube", Hypercube(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, BOX4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HYPERSPHERE)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hypersphere", Hypersphere(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, SPHERE4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HYPERCAPSULE)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hypercapsule", Hypercapsule(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, CAPSULE4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HYPERCYLINDER)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hypercylinder", Hypercylinder(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HYPERCONE)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hypercone", Hypercone(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HYPERPOT)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hyperpot", Hyperpot(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == TRIPRISM)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("TriPrism", TriPrism(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}

					if (this->buildCol == HYPERSLOPE)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hyperslope", Hyperslope(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HYPERQUAD)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("DoubleQuads4d", DoubleQuads4d(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == PENTACHORON)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Pentachoron", Pentachoron(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HYPERPYRAMID)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Pyramid4D", Pyramid4D(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HEXADECACHORON)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hexadecachoron", Hexadecachoron(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
						
					if (this->buildCol == HEXACOSICHORON)
					{
						this->rigidBodies4D.push_back(new RigidBody4D("Hexacosichoron", Hexacosichoron(this->buildScale / 2.f), this->hittingPos4D + glm::vec4(0.f, this->buildScale.y / 2.f - 0.01f, 0.f, 0.f), this->buildRotation, this->buildScale,
							this->buildParameter.x, this->buildParameter.y, this->buildParameter.z, this->buildParameter.w,
							this->isGravity, false, this->initialVelocity, this->initialAngularVelocity, this->isSpecular, this->wallTexs3D[this->buildTexture], 0.f, this->buildColor, MESH4D, true, this->shaders[this->buildShader]));
					}
					if (this->isIlluminate)
					{
						if (this->pointLights4D.size() >= 12)
						{
							this->isIlluminate = false;
						}
					}
					if (this->isIlluminate)
					{
						this->pointLights4D.push_back(new PointLight4D(this->particleTexs3D[PARTICLE1], glm::vec4(), this->rigidBodies4D.size()-1, this->lightIntensity, this->lightColor, this->lightScale.x, this->lightScale.y, this->lightScale.z, this->lightScale.w));
						update_point_light4d(this->pointLights4D, this->shaders[WALLD4], this->shaders[TERRAIND4]);
					}
				}
				if (this->buildMode == BUILD_POOL_TABLE)
				{
					shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2) + size_of_walls4d(this->groups), 28);
					shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2) + size_of_walls4d(this->groups), 28);
					generate_pool_table4D(get_cap_position4D(this->hittingPos4D), glm::vec4(1.27f, 1.27f, 2.54f, 1.27f), 1.f, true, this->wallTexs3D[WOODX], true, this->wallTexs3D[GRASS], true, this->wallTexs3D[WOODY], &this->walls4D, this->shaders[this->buildShader]);
					this->groups = pack_group(this->groups, &this->walls4D, &this->terrains4D);
				}
				if (this->buildMode == BUILD_POOL)
				{
					shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, this->rigidBodies4D.size(), 1);
					shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->rigidBodies4D.size(), 1);
					generate_billiard4D(this->hittingPos4D, this->wallTexs3D[this->buildTexture], &this->rigidBodies4D, this->isGravity, this->shaders[this->buildShader]);
				}
				if (this->buildMode == BUILD_DYNAMITE)
				{
					if (!this->isRigidBody)
					{
						shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2,this->groups, this->walls4D,this->dynamites4D), 1);
						shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2,this->groups, this->walls4D, this->dynamites4D), 1);
						generate_dynamites4D(this->hittingPos4D, this->wallTexs3D[WHITECONCRETE], &this->dynamites4D, this->shaders[this->buildShader]);
					}
					if (this->isRigidBody)
					{
						shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2), 1);
						shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, size_of_objects4d(this->rigidBodies4D, this->dynamites4D2), 1);
						generate_dynamites4D(this->hittingPos4D + glm::vec4(0, -0.01f, 0, 0), this->wallTexs3D[WHITECONCRETE], &this->dynamites4D2,this->isGravity, this->shaders[this->buildShader]);
					}
				}
			}
			if (this->buildMode == BUILD_STICK)
			{
				this->hitIndex = ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D, this->dynamites4D, true,true,false,this->camera.position4D, this->camera.forward4D, this->camera.right4D, &this->hitPosNear);
				if (this->hitIndex > -1)
				{
					if (this->springs4D.size() != 0)
					{
						if (this->springs4D[this->springs4D.size() - 1]->index2 != -1)
						{
							//
							int size = this->sticks4D.size();
							if (size != 0)
							{
								if (this->sticks4D[size - 1]->index2 != -1)
								{
									this->sticks4D.push_back(new Stick4D(glm::vec4(0.f), this->hitIndex, -1, this->stickLength, this->wallTexs3D[WHITECONCRETE], this->buildColor, this->shaders[this->buildShader]));
								}
								if (this->sticks4D[size - 1]->index2 == -1 && this->sticks4D[size - 1]->index1 != this->hitIndex)
								{
									this->sticks4D[size - 1]->index2=this->hitIndex;
								}
							}
							if (size == 0)
							{
								this->sticks4D.push_back(new Stick4D(glm::vec4(0.f), this->hitIndex, -1, this->stickLength, this->wallTexs3D[WHITECONCRETE], this->buildColor, this->shaders[this->buildShader]));
							}
							//
						}
						if (this->springs4D[this->springs4D.size() - 1]->index2 == -1 && this->springs4D[this->springs4D.size() - 1]->index1 != this->hitIndex)
						{
							this->springs4D[this->springs4D.size() - 1]->index2=this->hitIndex;
						}
					}
					if (this->springs4D.size() == 0)
					{
						//
						int size = this->sticks4D.size();
						if (size != 0)
						{
							if (this->sticks4D[size - 1]->index2 != -1)
							{
								this->sticks4D.push_back(new Stick4D(glm::vec4(0.f), this->hitIndex, -1, this->stickLength, this->wallTexs3D[WHITECONCRETE], this->buildColor, this->shaders[this->buildShader]));
							}
							if (this->sticks4D[size - 1]->index2 == -1 && this->sticks4D[size - 1]->index1 != this->hitIndex)
							{
								this->sticks4D[size - 1]->index2=this->hitIndex;
							}
						}
						if (size == 0)
						{
							this->sticks4D.push_back(new Stick4D(glm::vec4(0.f), this->hitIndex, -1, this->stickLength, this->wallTexs3D[WHITECONCRETE], this->buildColor, this->shaders[this->buildShader]));
						}
						//
					}
				}
			}
			if (this->buildMode == BUILD_SPRING)
			{
				this->hitIndex = ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D, this->dynamites4D, true,true,false,this->camera.position4D, this->camera.forward4D, this->camera.right4D, &this->hitPosNear);
				if (this->hitIndex > -1)
				{
					if (this->sticks4D.size() != 0)
					{
						if (this->sticks4D[this->sticks4D.size() - 1]->index2 != -1)
						{
							//
							int size = this->springs4D.size();
							if (size != 0)
							{
								if (this->springs4D[size - 1]->index2 != -1)
								{
									this->springs4D.push_back(new Spring4D(glm::vec4(0.f), this->hitIndex, -1, this->springLength, this->springStrength, this->wallTexs3D[GREEN], this->buildColor, this->shaders[this->buildShader]));
								}
								if (this->springs4D[size - 1]->index2 == -1 && this->springs4D[size - 1]->index1 != this->hitIndex)
								{
									this->springs4D[size - 1]->index2=this->hitIndex;
								}
							}
							if (size == 0)
							{
								this->springs4D.push_back(new Spring4D(glm::vec4(0.f), this->hitIndex, -1, this->springLength, this->springStrength, this->wallTexs3D[GREEN], this->buildColor, this->shaders[this->buildShader]));
							}
							//
						}
						if (this->sticks4D[this->sticks4D.size() - 1]->index2 == -1 && this->sticks4D[this->sticks4D.size() - 1]->index1 != this->hitIndex)
						{
							this->sticks4D[this->sticks4D.size() - 1]->index2=this->hitIndex;
						}
					}
					if (this->sticks4D.size() == 0)
					{
						int size = this->springs4D.size();
						if (size != 0)
						{
							if (this->springs4D[size - 1]->index2 != -1)
							{
								this->springs4D.push_back(new Spring4D(glm::vec4(0.f), this->hitIndex, -1, this->springLength, this->springStrength, this->wallTexs3D[GREEN], this->buildColor, this->shaders[this->buildShader]));
							}
							if (this->springs4D[size - 1]->index2 == -1 && this->springs4D[size - 1]->index1 != this->hitIndex)
							{
								this->springs4D[size - 1]->index2=this->hitIndex;
							}
						}
						if (size == 0)
						{
							this->springs4D.push_back(new Spring4D(glm::vec4(0.f), this->hitIndex, -1, this->springLength, this->springStrength, this->wallTexs3D[GREEN], this->buildColor, this->shaders[this->buildShader]));
						}
					}
				}
			}
		}
	}
	if (this->isFixedTime)
	{
		if (this->buildMode == BUILD_STICK || this->buildMode == BUILD_SPRING)
		{
			if (this->sticks4D.size() != 0) {
				if (this->sticks4D[this->sticks4D.size() - 1]->index2 == -1)
				{
					this->sticks4D[this->sticks4D.size() - 1]->fixPoint4D = this->camera.frontPosition4D;
				}
			}
			if (this->springs4D.size() != 0) {
				if (this->springs4D[this->springs4D.size() - 1]->index2 == -1)
				{
					this->springs4D[this->springs4D.size() - 1]->fixPoint4D = this->camera.frontPosition4D;
				}
			}
		}
	}
	if (this->mode == DELETING)
	{
		if (this->inputs[2]->getMouseOnPress(this->window, GLFW_MOUSE_BUTTON_2))
		{
			this->hitIndex = ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D, this->dynamites4D, true,true,false,this->camera.position4D, this->camera.forward4D, this->camera.right4D, &this->hitPosNear);
			if (this->hitIndex > -1)
			{
				if (this->hitIndex < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2))
				{
					erase_animation4D(&this->shifts4D,&this->floats4D,&this->rotates4D, this->hitIndex);
					shift_animation4D(this->shifts4D, this->floats4D,this->rotates4D, this->hitIndex,-1);
					erase_joint4d(&this->sticks4D, &this->springs4D, &this->hingeConstraints, this->hitIndex);
					shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->hitIndex,-1);
					erase_point_light4d(&this->pointLights4D, this->shaders[WALLD4], this->shaders[TERRAIND4], this->hitIndex);
					shift_point_light4d(this->pointLights4D, this->hitIndex, -1);
					erase_rigidbody4d(&this->rigidBodies4D, &this->dynamites4D2, this->hitIndex);
				}
				else if (this->hitIndex >= size_of_objects4d(this->rigidBodies4D, this->dynamites4D2)&& this->hitIndex < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2, this->groups))
				{
					if (find_wall4d(this->groups, this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2))->objectName != "Ground")
					{
						erase_joint4d(&this->sticks4D, &this->springs4D, &this->hingeConstraints, this->hitIndex);
						shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->hitIndex, -1);
						erase_wall4d(this->groups, this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2));
					}
				}
				else if (this->hitIndex >= size_of_objects4d(this->rigidBodies4D, this->dynamites4D2, this->groups) && this->hitIndex < size_of_objects4d(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D))
				{
					if (this->walls4D[this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2, this->groups)]->objectName != "Ground")
					{
						erase_joint4d(&this->sticks4D, &this->springs4D, &this->hingeConstraints, this->hitIndex);
						shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->hitIndex, -1);
						this->walls4D.erase(this->walls4D.begin() + this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2, this->groups));
					}
				}
				else if (this->hitIndex >= size_of_objects4d(this->rigidBodies4D, this->dynamites4D2,this->groups,this->walls4D))
				{
					erase_joint4d(&this->sticks4D, &this->springs4D, &this->hingeConstraints, this->hitIndex);
					shift_joint4d(this->sticks4D, this->springs4D, this->hingeConstraints, this->hitIndex, -1);
					this->dynamites4D.erase(this->dynamites4D.begin() + this->hitIndex - size_of_objects4d(this->rigidBodies4D, this->dynamites4D2,this->groups,this->walls4D));
				}
				this->hitIndex = -1;
			}
		}
	}
	if (this->mode == AREA_DELETING)
	{
		if (this->inputs[2]->getMouseOnPress(this->window, GLFW_MOUSE_BUTTON_2))
		{
			ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D, this->dynamites4D, true,true, true, this->camera.position4D, this->camera.forward4D, this->camera.right4D, &this->hittingPos4D);
		}
		if (glfwGetMouseButton(this->window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
		{
			glm::vec4 endPos;
			ray::detect_object4d_index(this->rigidBodies4D, this->dynamites4D2, this->groups, this->walls4D, this->dynamites4D, true,true, true, this->camera.position4D, this->camera.forward4D, this->camera.right4D, &endPos);
			this->deleteMap3D->washArea();
			this->deleteMap3D->selectArea(glm::vec3(this->hittingPos4D.x, this->hittingPos4D.z, this->hittingPos4D.w),
				glm::vec3(endPos.x, endPos.z, endPos.w));
		}
		if (this->inputs[3]->getMouseOnRelease(this->window, GLFW_MOUSE_BUTTON_2))
		{
			this->deleteMap3D->getImageData();
		}
	}
}