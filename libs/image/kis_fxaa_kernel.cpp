/*
 *  Copyright (c) 2017 Wolthera van Hövell tot Westerflier <griffinvalley@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "kis_fxaa_kernel.h"
#include "kis_global.h"
#include "kis_convolution_kernel.h"
#include <kis_convolution_painter.h>
#include <KoCompositeOpRegistry.h>
#include <QRect>
#include <KoColorSpace.h>
#include <kis_iterator_ng.h>
#include <QVector3D>

KisFXAAKernel::KisFXAAKernel()
{

}
/*
 * TODO: comment
 */

void KisFXAAKernel::applyFXAA(KisPaintDeviceSP device,
                              const QRect &rect,
                              const QBitArray &channelFlags,
                              KoUpdater *progressUpdater,
                              bool writeToAlpha)
{
    QPoint srcTopLeft = rect.topLeft();
    KisPainter finalPainter(device);
    finalPainter.setChannelFlags(channelFlags);
    finalPainter.setProgress(progressUpdater);


    QPoint srcTopLeft = rect.topLeft();

    KisConvolutionPainter painter(device);
    painter.setChannelFlags(channelFlags);
    painter.setProgress(progressUpdater);

    KisConvolutionKernelSP kernelHoriz = NULL;
    painter.applyMatrix(kernelHoriz, device, srcTopLeft, srcTopLeft, rect.size(), BORDER_REPEAT);

}
