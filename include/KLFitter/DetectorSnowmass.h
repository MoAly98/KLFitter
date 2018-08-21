/*
 * Copyright (c) 2009--2018, the KLFitter developer team
 *
 * This file is part of KLFitter.
 *
 * KLFitter is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * KLFitter is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with KLFitter. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KLFITTER_DETECTORSNOWMASS_H_
#define KLFITTER_DETECTORSNOWMASS_H_

#include <memory>
#include <string>

#include "KLFitter/DetectorBase.h"

// ---------------------------------------------------------

namespace KLFitter {
class ResolutionBase;

/**
 * A class for describing the Snowmass detector. This class
 * holds the description of the Snowmass detector.
 */
class DetectorSnowmass : public DetectorBase {
 public:
  /**
   * The default constructor.
   * @param folder The folder with transfer function parameters.
   */
  explicit DetectorSnowmass(std::string folder = "");

  /// The (defaulted) destructor.
  ~DetectorSnowmass();

  /** \name Member functions (Get)  */
  /* @{ */

  /**
   * Return the energy resolution of light-jets.
   * @param eta The eta of the particle.
   * @return A pointer to the energy resolution object.
   */
  ResolutionBase* ResEnergyLightJet(double eta = 0.) override;

  /**
   * Return the energy resolution of b-jets.
   * @param eta The eta of the particle.
   * @return A pointer to the energy resolution object.
   */
  ResolutionBase* ResEnergyBJet(double eta = 0.) override;

  /**
   * Return the energy resolution of electrons.
   * @param eta The eta of the particle.
   * @return A pointer to the energy resolution object.
   */
  ResolutionBase* ResEnergyElectron(double eta = 0.) override;

  /**
   * Return the momentum resolution of muons.
   * @param eta The eta of the particle.
   * @return A pointer to the momentum resolution object.
   */
  ResolutionBase* ResEnergyMuon(double eta = 0.) override;

  /**
   * Return the missing ET resolution.
   * @return A pointer to the missing ET resolution.
   */
  ResolutionBase* ResMissingET() override;

  /* @} */

 private:
  /// The energy resolution of light jets for different eta regions.
  std::unique_ptr<ResolutionBase> m_res_jet_energy_eta1;
  std::unique_ptr<ResolutionBase> m_res_jet_energy_eta2;
  std::unique_ptr<ResolutionBase> m_res_jet_energy_eta3;

  /// The energy resolution of electrons for different eta regions.
  std::unique_ptr<ResolutionBase> m_res_electron_energy_eta1;
  std::unique_ptr<ResolutionBase> m_res_electron_energy_eta2;

  /// The momentum resolution of muons for different eta regions.
  std::unique_ptr<ResolutionBase> m_res_muon_momentum_eta1;
  std::unique_ptr<ResolutionBase> m_res_muon_momentum_eta2;

  /// Missing ET resolution in x and y
  std::unique_ptr<ResolutionBase> m_res_missing_ET;

  /// The eta binning for jets
  double m_jet_eta_bin_1;
  double m_jet_eta_bin_2;
  double m_jet_eta_bin_3;

  /// The eta binning for electrons
  double m_electron_eta_bin_1;
  double m_electron_eta_bin_2;

  /// The eta binning for muons
  double m_muon_eta_bin_1;
  double m_muon_eta_bin_2;

};
}  // namespace KLFitter

#endif  // KLFITTER_DetectorSnowmass_H_
