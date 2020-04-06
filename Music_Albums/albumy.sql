-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Aug 21, 2016 at 09:07 PM
-- Server version: 10.1.13-MariaDB
-- PHP Version: 7.0.8

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `muzyka`
--

-- --------------------------------------------------------

--
-- Table structure for table `albumy`
--

CREATE TABLE `albumy` (
  `id` int(11) NOT NULL,
  `nazwa` text COLLATE utf8_polish_ci NOT NULL,
  `wykonawca` text COLLATE utf8_polish_ci NOT NULL,
  `rok` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_polish_ci;

--
-- Dumping data for table `albumy`
--

INSERT INTO `albumy` (`id`, `nazwa`, `wykonawca`, `rok`) VALUES
(1, 'Primo Victoria', 'Sabaton', 2005),
(2, 'Coat of Arms', 'Sabaton', 2010),
(3, 'Mesmerize', 'System of a Down', 2005),
(4, 'Toxicity', 'System of a Down', 2001),
(5, 'The Doors', 'The Doors', 1967),
(6, 'Strange days', 'The Doors', 1967),
(7, 'L.A. Woman', 'The Doors', 1971),
(8, 'Alive she cried', 'The Doors', 1983),
(9, 'Gothic', 'Paradise Lost', 1991),
(10, 'Icon', 'Paradise Lost', 1993),
(11, 'Draconian Times', 'Paradise Lost', 1995),
(12, 'One second', 'Paradise Lost', 1997),
(13, 'Host', 'Paradise Lost', 1999),
(14, 'Believe in Nothing', 'Paradise Lost', 2001),
(15, 'Symbol of life', 'Paradise Lost', 2002),
(16, 'Faith Divides Us - Death Unites Us', 'Paradise Lost', 2009),
(17, 'Amok', 'Sentenced', 1995),
(18, 'Frozen', 'Sentenced', 1998),
(19, 'Crimson', 'Sentenced', 2000),
(20, 'The Cold White Light', 'Sentenced', 2002);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `albumy`
--
ALTER TABLE `albumy`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `albumy`
--
ALTER TABLE `albumy`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
