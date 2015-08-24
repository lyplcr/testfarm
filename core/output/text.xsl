<?xml version="1.0"?>

<!-- TestFarm Report Text Display

This file is part of TestFarm,
the Test Automation Tool for Embedded Software.
Please visit http://www.testfarm.org.

TestFarm is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

TestFarm is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with TestFarm.  If not, see <http://www.gnu.org/licenses/>.
-->

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template name="text-display">
  <xsl:param name="string"/>
  <xsl:param name="filter"/>
  <xsl:variable name="lf" select="'&#xA;'"/>
  <xsl:choose>
    <xsl:when test="contains($string,$lf)">
      <xsl:if test="not(starts-with($string, $lf))">
        <xsl:if test="starts-with($string, $filter)">
          <xsl:variable name="line" select="substring-before($string,$lf)"/>
          <xsl:value-of select="substring-after($line,$filter)" disable-output-escaping="yes"/><br/>
        </xsl:if>
      </xsl:if>
      <xsl:call-template name="text-display">
        <xsl:with-param name="string" select="substring-after($string,$lf)"/>
        <xsl:with-param name="filter" select="$filter"/>
      </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="$string"/>
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>


<xsl:template name="stdio-display">
  <blockquote><pre class="dump">
    <xsl:for-each select="STDIO">
      <div id="{@channel}">
        <xsl:value-of select="." disable-output-escaping="yes"/>
      </div>
    </xsl:for-each>
  </pre></blockquote>
</xsl:template>


<xsl:template name="duration-display">
  <xsl:param name="duration"/>
  <xsl:variable name="seconds0" select="$duration div 1000"/>
  <xsl:variable name="mins0" select="floor($seconds0 div 60)"/>
  <xsl:choose>
    <xsl:when test="$mins0 > 0">
      <xsl:variable name="hours" select="floor($mins0 div 60)"/>
      <xsl:variable name="mins" select="$mins0 - 60 * $hours"/>
      <xsl:variable name="seconds" select="floor($seconds0 - 60 * $mins0)"/>
      <xsl:value-of select="format-number($hours, '00')"/>:<xsl:value-of select="format-number($mins, '00')"/>:<xsl:value-of select="format-number($seconds, '00')"/>
    </xsl:when>
    <xsl:otherwise>
      <xsl:value-of select="format-number($seconds0, '0.000')"/> s
    </xsl:otherwise>
  </xsl:choose>
</xsl:template>

</xsl:stylesheet>
