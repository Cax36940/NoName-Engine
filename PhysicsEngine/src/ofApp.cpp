#pragma once
#include "ofApp.h"
#include "System/CollidersComponentRegistry.hpp"
#include "System/CollisionsRegistry.hpp"
#include "System/GraphicsComponentRegistry.hpp"
#include "System/ParticleForceRegistry.hpp"
#include "System/PhysicsComponentRegistry.hpp"
#include "System/UpdatesComponentRegistry.hpp"
#include "Entity/ParticleFactory.hpp"


#include "Entity/ParticleFactory.hpp"

//--------------------------------------------------------------
void ofApp::setup() {

	// Inititalize environment
	backgroundPicture.load("images/bg_picture.png");
	myfont.load("calibri", 20);

	timeLastFrame = std::chrono::high_resolution_clock::now();

	mouse_x = 0;
	mouse_y = 0;
	drag_particle = nullptr;


	// Initialize scene entities
	current_selected_blob = 0;
	second_selected_blob = 0;
	nb_of_particles_in_blob = 20;
	particle_list.reserve(nb_of_particles_in_blob);
	blobs.reserve(nb_of_particles_in_blob);
	blobs.emplace_back(Vector3(1000, 500, 0), nb_of_particles_in_blob);
	blobs[current_selected_blob].sprite.set_visible_outline(true);

	gravity = GravityForce(10);
	mouse_pull_force = PullForce(10, Vector3(0, 0, 0));

	blob_size_counter = CountHUD(30, WINDOW_HEIGHT - 20, 0, &myfont);

}

//--------------------------------------------------------------
void ofApp::update() {
	// Calc deltaTime
	auto time = std::chrono::high_resolution_clock::now();
	auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(time - timeLastFrame).count() / 1000.; //durée de calcul d'une frame
	timeLastFrame = time;

	// Register forces from physics components
	PhysicsComponentRegistry::register_all_physics();

	// Checking collisions
	CollidersComponentRegistry::check_collisions();
	CollisionsRegistry::solve_collisions();

	// Applying forces


	if (mouse_pressed && !drag_particle) {
		mouse_pull_force.set_position(Vector3(mouse_x, mouse_y, 0));
	}

	for (Blob& blob : blobs) {
		for (DefaultParticle& part : blob.particles) {
			ParticleForceRegistry::add(part.get_physical_particle(), &gravity);
			if (mouse_pressed && !drag_particle && &blob == &blobs[current_selected_blob]) {
				ParticleForceRegistry::add(part.get_physical_particle(), &mouse_pull_force);
			}
		}
	}

	ParticleForceRegistry::update_forces(delta);


	// Update mouse control on particle
	if (drag_particle)
	{
		drag_particle->get_physical_particle()->clear_accum();
		drag_particle->get_physical_particle()->set_position(Vector3(mouse_x, mouse_y, 0));
		drag_particle->get_physical_particle()->set_velocity(Vector3(0, 0, 0));
	}

	blob_size_counter.set_value(blobs[current_selected_blob].particles.size());

	// Updating every object
	UpdatesComponentRegistry::update_all(delta);

	// Clear for next update
	ParticleForceRegistry::clear();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetupScreenOrtho(WINDOW_WIDTH, WINDOW_HEIGHT, -1000, 1000);
	ofSetColor(255);
	backgroundPicture.draw(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	myfont.drawString("Click on screen to attract the selected blob\nSPACE BAR: split or merge selected blob(s)\nH: set visibility of skeleton\nC: change selected blob\nV: select second blob", 30, 40);
	GraphicsComponentRegistry::draw_all();

	blob_size_counter.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'h') { // Show/Hide the skeleton of the currently selected blob 
		blobs[current_selected_blob].flip_inside_visible();
	}
	if (key == 'c') { // Change currently selected blob
		blobs[current_selected_blob].sprite.set_visible_outline(false);
		blobs[second_selected_blob].sprite.set_visible_outline(false);
		current_selected_blob = (current_selected_blob + 1) % blobs.size();
		second_selected_blob = current_selected_blob;
		blobs[current_selected_blob].sprite.set_visible_outline(true);
	}
	if (key == 'v') { // Change second selected blob
		if (second_selected_blob != current_selected_blob) {
			blobs[second_selected_blob].sprite.set_visible_outline(false);
		}
		second_selected_blob = (second_selected_blob + 1) % blobs.size();
		blobs[second_selected_blob].sprite.set_visible_outline(true);
	}
	if (key == ' ') { // Split/Merge the blob
		bool inside_visible = blobs[current_selected_blob].is_inside_visible();
		if (current_selected_blob == second_selected_blob) {// If one blob is selected, split the blob

			// Just a ref to the particles list for better lisibility
			const std::vector<DefaultParticle>& particle_list = blobs[current_selected_blob].particles;

			if (particle_list.size() < 6) {
				return;
			}
			
			// Compute the size of the two blobs
			size_t first_size = particle_list.size() / 2;
			size_t second_size = particle_list.size() - first_size;

			// Create the two resulting blobs
			Blob first_blob(particle_list, 0, first_size);
			Blob second_blob(particle_list, first_size, second_size);

			// Replace current blob with the two created blobs
			blobs.erase(std::next(blobs.begin(), current_selected_blob));
			blobs.push_back(first_blob);
			blobs.push_back(second_blob);
			current_selected_blob = blobs.size() - 1;
			second_selected_blob = current_selected_blob;
			blobs[current_selected_blob].sprite.set_visible_outline(true);
			if (inside_visible) {
				blobs[current_selected_blob].flip_inside_visible();
				blobs[current_selected_blob-1].flip_inside_visible();
			}
		}
		else { // Otherwise merge the blobs
			// Ensure current is higher to be removed the first
			if (current_selected_blob < second_selected_blob) {
				std::swap(current_selected_blob, second_selected_blob);
			}

			Blob first_blob = blobs[current_selected_blob];
			Blob second_blob = blobs[second_selected_blob];
			blobs.erase(std::next(blobs.begin(), current_selected_blob));
			blobs.erase(std::next(blobs.begin(), second_selected_blob));
			blobs.emplace_back(first_blob, second_blob);
			current_selected_blob = blobs.size() - 1;
			second_selected_blob = current_selected_blob;
			blobs[current_selected_blob].sprite.set_visible_outline(true);
			if (inside_visible) {
				blobs[current_selected_blob].flip_inside_visible();
			}
		}

		



	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	mouse_x = x;
	mouse_y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	mouse_x = x;
	mouse_y = y;
	mouse_pressed = true;

	for (DefaultParticle* particle_it : particle_list) {

		const Vector3 pos_souris(x, y, 0);
		const Vector3& pos_particle = particle_it->particle.get_position();
		int rayon = particle_it->sprite.get_size();

		const Vector3 distance = pos_souris - pos_particle;
		if (Vector3::norm(distance) < rayon) {
			drag_particle = particle_it;
			return;
		}
	}
	drag_particle = nullptr;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mouse_pressed = false;
	drag_particle = nullptr;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
